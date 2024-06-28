#ifndef SENTRY_LOGGER_H
#define SENTRY_LOGGER_H

#include <QApplication>
#include <QWidget>
#include <QString>
#include <QCoreApplication>
#include <QSysInfo>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QBuffer>

#include <sentry.h>
#include "qstandardpaths.h" 



class PathConfig {
public:
    static QString appDataLocation() {
        return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    }
};


struct SentryLoggerOptions {
    QString dsn;
    QString release;
    QString environment;
    QString database;
};

class SentryLogger {
public:
    static SentryLogger& instance() {
        static SentryLogger instance;
        return instance;
    }

    bool setup(const SentryLoggerOptions& options);
    void captureEvent(sentry_level_t level, const QString& loggerName, const QString& message);

private:
    SentryLogger() : networkManager(new QNetworkAccessManager) {}
    ~SentryLogger() {
        delete networkManager;
    }

    SentryLogger(const SentryLogger&) = delete;
    SentryLogger& operator=(const SentryLogger&) = delete;

    QNetworkAccessManager* networkManager;
};

#endif
