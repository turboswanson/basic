#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QThread>
#include "file_processor/file_processor.h"
#include "word_count_model/word_count_model.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    WordCountModel model;
    FileProcessor *processor = new FileProcessor;
    QThread *processorThread = new QThread;

    engine.rootContext()->setContextProperty("wordModel", &model);
    engine.rootContext()->setContextProperty("fileProcessor", processor);
    engine.load(QUrl(QStringLiteral("qrc:/appView.qml")));

    if (engine.rootObjects().isEmpty()) // looks like a crutch
    {
        qWarning() << "No QML root objects loaded!";
        return -1;
    }

    auto *rootObject = engine.rootObjects().first();

    QObject::connect(processor, &FileProcessor::progressChanged, rootObject, [=](double value) {
        QMetaObject::invokeMethod(rootObject, "updateProgress", Q_ARG(QVariant, value));
    });

    processor->moveToThread(processorThread);
    processorThread->start();

    QObject::connect(
        processor,
        &FileProcessor::fileProcessed,
        &model,
        [&model](const QVector<QPair<QString, int>> &data) { model.setWordCount(data); },
        Qt::QueuedConnection);

    QObject::connect(
        processor,
        &FileProcessor::processingHasCancelled,
        &model,
        [&model]() { model.cleanModel(); },
        Qt::QueuedConnection);

    QObject::connect(&app, &QCoreApplication::aboutToQuit, processorThread, &QThread::quit);
    QObject::connect(processorThread, &QThread::finished, processorThread, &QObject::deleteLater);
    QObject::connect(processorThread, &QThread::finished, processor, &QObject::deleteLater);

    return app.exec();
}
