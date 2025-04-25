#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "word_count_model/word_count_model.h"
#include "file_processor/file_processor.h"

void signalHandler(FileProcessor *processor, WordCountModel &model, QThread *thread)
{
    QObject *connectionContextObject = new QObject;

    QObject::connect(thread, &QThread::finished, processor, &QObject::deleteLater);
    QObject::connect(thread, &QThread::finished, thread, &QObject::deleteLater);

    QObject::connect(processor, &FileProcessor::fileProcessed, connectionContextObject,
                     [&model,thread](const QVector<QPair<QString,int>>& data)
    {
        model.setWordCount(data);
    });

    QObject::connect(processor, &FileProcessor::processingHasCancelled, connectionContextObject,
                     [&model,thread]()
    {
        model.cleanModel();
    });



}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    WordCountModel model;

    FileProcessor *processor = new FileProcessor;
    QThread *thread = new QThread;

    engine.rootContext()->setContextProperty("wordModel", &model);
    engine.rootContext()->setContextProperty("fileProcessor", processor);

    processor->moveToThread(thread);

    signalHandler(processor,model,thread);

    QObject::connect(&app, &QCoreApplication::aboutToQuit, thread, &QThread::quit);

    engine.load(QUrl(QStringLiteral("qrc:/appView.qml")));

    auto roots = engine.rootObjects();

    if (roots.isEmpty()) {
        qDebug() << "Engine root Error!!!!";
        return -1;
    }

    auto *root = roots.first();

    QObject::connect(&app, &QCoreApplication::aboutToQuit, thread, &QThread::quit);
    QObject::connect(root, SIGNAL(fileHasChosen(QString)), processor,SLOT(setFilePath(QString)));
    QObject::connect(root, SIGNAL(startFileProcessing()), processor,SLOT(startFileProcessing()));
    QObject::connect(processor, &FileProcessor::progressChanged, root, [=](double value) {
        QMetaObject::invokeMethod(root, "updateProgress", Q_ARG(QVariant, value));
    });

    qDebug() << "main1 thread:" << QThread::currentThread();

    thread->start();
    qDebug() << "main2 thread:" << QThread::currentThread();

    return app.exec();
}


