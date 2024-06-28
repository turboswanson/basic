#include "sentry_logger.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString dsn = "https://e22aba8a1e323b9de1bf30b34b301b0f@o4507496679014400.ingest.de.sentry.io/4507496683602000";
    QString release = QString("%1 %2 %3")
                           .arg(app.platformName(), QSysInfo::buildCpuArchitecture(),
                                QCoreApplication::applicationVersion());
    QString environment = "develop";
    QString database = PathConfig::appDataLocation() + "/.sentry-native";

    SentryLoggerOptions loggerOptions;
    loggerOptions.dsn = dsn;
    loggerOptions.release = release;
    loggerOptions.environment = environment;
    loggerOptions.database = database;

    if (!SentryLogger::instance().setup(loggerOptions))
        qWarning("Failed to initialize SentryLogger");

    SentryLogger::instance().captureEvent(SENTRY_LEVEL_INFO, "custom", "SAY HELLO TO KONSTANTIN FROM UBEGO");

    int result = app.exec();

    return result;
}
