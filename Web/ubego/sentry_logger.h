#pragma once

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

enum LogLevel {
    LOG_LEVEL_DEBUG = -1,
    LOG_LEVEL_INFO = 0,
    LOG_LEVEL_WARNING = 1,
    LOG_LEVEL_ERROR = 2,
    LOG_LEVEL_FATAL = 3
};

static QtMessageHandler messageHandlerChain = nullptr;

void sentryHandleMessage(QtMsgType type, const QMessageLogContext& context, const QString& msg);

class PathConfig {
public:
    static QString appDataLocation() {
        return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    }
};

struct SentryDSN {
    QString scheme;
    QString host;
    QString projectId;
};

struct CustomTransportState {
    QNetworkAccessManager networkManager;
    SentryDSN dsn;
};


struct SentryLoggerOptions {
    QString handler_path;
    QString dsn;
    QString release;
    QString environment;
    QString database;
    int debug;
};

class SentryLogger {
public:
    static SentryLogger& instance();

    bool setup(const SentryLoggerOptions& options);
    void captureEvent(sentry_level_t level, const QString& loggerName, const QString& message);
    LogLevel minLogLevel() const;

private:
    SentryLogger(); 
    ~SentryLogger();

    SentryLogger(const SentryLogger&) = delete;
    SentryLogger& operator=(const SentryLogger&) = delete;
    SentryLogger(SentryLogger&&) = delete;
    SentryLogger& operator=(SentryLogger&&) = delete;

    LogLevel _minLogLevel {LOG_LEVEL_DEBUG};

    CustomTransportState transport_state;
};

