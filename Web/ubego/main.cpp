#include "sentry_logger.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if (!SentryLogger::instance().setup(SentryLoggerOptions{
         .handler_path = "/home/mitchelk/Downloads/ubego/sentry-native/install/bin/crashpad_handler",
        //  .dsn = "https://7e87fa13676fd071b8970def6130bb60@o4507590140166144.ingest.de.sentry.io/4507590164545616",
         .dsn = "https://e81b50d9a31543af916ddf7a602a3cfa@o206498.ingest.us.sentry.io/4504051301220352",
         .release = QString("%1 %2 %3").arg(app.platformName(), QSysInfo::buildCpuArchitecture(),QCoreApplication::applicationVersion()),
         .environment = "develop",
         .database = PathConfig::appDataLocation() + "/.sentry-native",
         .debug = 1,
    })) {
        qWarning("Failed to initialize SentryLogger");
    }

    // char *c = nullptr;

    // qDebug() << *c;

    // qDebug() << "This is a debug message #21";

    // qInfo() << "This is an info message #21";

    // qWarning() << "This is a warning message #21";

    qCritical() << "This is a critical error message #21";

    qInstallMessageHandler(messageHandlerChain);

    messageHandlerChain = nullptr;

    return app.exec();
  
}


    // SentryLogger::instance().captureEvent(SENTRY_LEVEL_INFO, "custom", "GOOD AFTERNOON#4");
   

    // qDebug() << "This is a debug message #21";

    // qInfo() << "This is an info message #21";

    // qWarning() << "This is a warning message #21";

    // qCritical() << "This is a critical error message #21";

    // qInstallMessageHandler(messageHandlerChain);
    // messageHandlerChain = nullptr;

    

