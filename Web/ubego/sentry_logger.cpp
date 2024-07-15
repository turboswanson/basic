#include "sentry_logger.h"
#include <QDebug>
#include <iostream>

void ubego_transport(sentry_envelope_t *envelope, void *state) {
    CustomTransportState *transportState = static_cast<CustomTransportState *>(state);

    size_t envelope_size;
    char *envelope_buffer = sentry_envelope_serialize(envelope, &envelope_size);

    if (envelope_buffer) {
        QByteArray envelopeData(envelope_buffer, envelope_size);
        auto buffer = std::make_shared<QBuffer>();
        buffer->setData(envelopeData);
        buffer->open(QIODevice::ReadOnly);
         
        SentryDSN dsn = transportState->dsn;

        QUrl sentryUrl(QString("%1://%2/api/%3/envelope/")
                       .arg(dsn.scheme)
                        .arg(dsn.host)
                       .arg(dsn.projectId));

        QNetworkRequest request(sentryUrl);

    //    QUrl url_(QString("https://o206498.ingest.us.sentry.io/api/4507600000516096/envelope/"));          
    //    QNetworkRequest request(url_);              

        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-sentry-envelope");
        
        QNetworkReply *reply = transportState->networkManager.post(request, buffer.get());

        QObject::connect(reply, &QNetworkReply::finished, [reply,buffer]() {
            if (reply->error() != QNetworkReply::NoError) {
                qDebug() << "Custom Transport - Network Error:" << reply->errorString();
            } else {
                qDebug() << "Custom Transport - Successfully sent envelope";
                qDebug() << "Custom Transport - Server Response:" << reply->readAll();
            }
            reply->deleteLater();
        });

        free(envelope_buffer);
    }

    sentry_envelope_free(envelope);
}

inline sentry_options_t *SentryOptionsHandling(const SentryLoggerOptions& options,sentry_transport_t *transport){
    sentry_options_t *sentryOptions = sentry_options_new();

    sentry_options_set_handler_path(sentryOptions,qPrintable(options.handler_path));
    sentry_options_set_dsn(sentryOptions, qPrintable(options.dsn));
    sentry_options_set_environment(sentryOptions, qPrintable(options.environment));
    sentry_options_set_database_path(sentryOptions, qPrintable(options.database));
    sentry_options_set_release(sentryOptions, qPrintable(options.release));
    sentry_options_set_debug(sentryOptions, options.debug);
    sentry_options_set_transport(sentryOptions, transport);

    return sentryOptions;    
}

inline sentry_level_e
qtMsgTypeItSentryLogLevel(const QtMsgType type,
                          const sentry_level_e defaultValue = SENTRY_LEVEL_DEBUG)
{
    switch (type)
    {
    case QtDebugMsg:
        return SENTRY_LEVEL_DEBUG;
    case QtInfoMsg:
        return SENTRY_LEVEL_INFO;
    case QtWarningMsg:
        return SENTRY_LEVEL_WARNING;
    case QtCriticalMsg:
        return SENTRY_LEVEL_ERROR;
    case QtFatalMsg:
        return SENTRY_LEVEL_FATAL;
    }

    return defaultValue;
}


void sentryHandleMessage(QtMsgType type, const QMessageLogContext& context,
                         const QString& msg)
{

    const sentry_level_e level = qtMsgTypeItSentryLogLevel(type);
    if (level >= static_cast<sentry_level_e>(SentryLogger::instance().minLogLevel()))
    {
        sentry_capture_event(sentry_value_new_message_event(level, context.category,
                                                            msg.toStdString().c_str()));
    }
    
}


SentryDSN parseDSN(const QString& dsn) {
    QUrl url(dsn);
    QStringList pathParts = url.path().split('/', Qt::SkipEmptyParts);

    QString projectId = pathParts.last();

    SentryDSN parsedDSN;
    parsedDSN.scheme = url.scheme();
    parsedDSN.host = url.host();
    parsedDSN.projectId = projectId;

    return parsedDSN;
}

bool SentryLogger::setup(const SentryLoggerOptions& options) {
    transport_state.dsn = parseDSN(options.dsn);
    sentry_transport_t *transport = sentry_transport_new(ubego_transport);
    sentry_transport_set_state(transport, &transport_state);
    sentry_set_level(static_cast<sentry_level_e>(SentryLogger::instance().minLogLevel()));
    messageHandlerChain = qInstallMessageHandler(sentryHandleMessage); 
    
    return(!sentry_init(SentryOptionsHandling(options,transport)));

}

void SentryLogger::captureEvent(sentry_level_t level, const QString& loggerName, const QString& message) {
    sentry_value_t event = sentry_value_new_message_event(
        level, 
        loggerName.toUtf8().constData(),
        message.toUtf8().constData()
    );
    sentry_capture_event(event);
}

SentryLogger :: SentryLogger() {}

SentryLogger& SentryLogger :: instance() {
    static SentryLogger instance;
    return instance;
}

LogLevel SentryLogger::minLogLevel() const
{
    return _minLogLevel;
}

SentryLogger :: ~SentryLogger() {
    sentry_close();
}

