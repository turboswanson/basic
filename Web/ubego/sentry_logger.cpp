#include "sentry_logger.h"

struct CustomTransportState {
    QNetworkAccessManager *networkManager;
};

void ubego_transport(sentry_envelope_t *envelope, void *state) {
    CustomTransportState *transportState = static_cast<CustomTransportState *>(state);

    size_t envelope_size;
    char *envelope_buffer = sentry_envelope_serialize(envelope, &envelope_size);

    if (envelope_buffer) {
        QByteArray envelopeData(envelope_buffer, envelope_size);
        QBuffer *buffer = new QBuffer;
        buffer->setData(envelopeData);
        buffer->open(QIODevice::ReadOnly);

        QNetworkRequest request(
            QUrl("https://o4507496679014400.ingest.de.sentry.io/api/4507496683602000/envelope/"));
                    
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-sentry-envelope");
        
        QNetworkReply *reply = transportState->networkManager->post(request, buffer);

        QObject::connect(reply, &QNetworkReply::finished, [reply, buffer]() {
            if (reply->error() != QNetworkReply::NoError) {
                qDebug() << "Custom Transport - Network Error:" << reply->errorString();
            } else {
                qDebug() << "Custom Transport - Successfully sent envelope";
                qDebug() << "Custom Transport - Server Response:" << reply->readAll();
            }
            reply->deleteLater();
            buffer->deleteLater();
        });

        free(envelope_buffer);
    }

    sentry_envelope_free(envelope);
}

bool SentryLogger::setup(const SentryLoggerOptions& options) {
    sentry_options_t *sentryOptions = sentry_options_new();
    sentry_options_set_dsn(sentryOptions, options.dsn.toUtf8().constData());
    sentry_options_set_release(sentryOptions, options.release.toUtf8().constData());
    sentry_options_set_environment(sentryOptions, options.environment.toUtf8().constData());
    sentry_options_set_database_path(sentryOptions, options.database.toUtf8().constData());
    sentry_options_set_handler_path(sentryOptions, "../sentry-native/install/bin/crashpad_handler");
    
    sentry_options_set_debug(sentryOptions, 1); 
    CustomTransportState *transportState = new CustomTransportState;
    transportState->networkManager = networkManager;

    sentry_transport_t *transport = sentry_transport_new(ubego_transport);
    sentry_transport_set_state(transport, transportState);
    sentry_options_set_transport(sentryOptions, transport);

    int initResult = sentry_init(sentryOptions);
    

    return initResult == 0;
}

void SentryLogger::captureEvent(sentry_level_t level, const QString& loggerName, const QString& message) {
    sentry_value_t event = sentry_value_new_message_event(
        level, 
        loggerName.toUtf8().constData(),
        message.toUtf8().constData()
    );
    sentry_capture_event(event);

    qDebug("Event captured: Level: %d, Logger: %s, Message: %s", level, qPrintable(loggerName), qPrintable(message));
}
