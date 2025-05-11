#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "word_count_model/word_count_model.h"
#include "file_processor/file_processor.h"
#include <QThread>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    WordCountModel model;

    FileProcessor *processor = new FileProcessor;
    QThread *processorThread = new QThread;

    processor->moveToThread(processorThread);
    thread->start();
    
    // QObject::connect(app,&QCoreApplication::aboutToQuit,processorThread, &QThread::quit);
    QObject::connect(app,&QCoreApplication::aboutToQuit,[=]()
    {
        if(processorThread->isRunning())
        {
            processorThread->quit();    
            processorThread->wait(500);
        }
        processorThread->deleteLater();
        processor->deleteLater();
    }
    // QObject::connect(processorThread, &QThread::finished, processorThread, &QObject::deleteLater);
    // QObject::connect(processorThread, &QThread::finished, processor, &QObject::deleteLater);

    QObject::connect(processor, &FileProcessor::fileProcessed, model,
                     [&model](const QVector<QPair<QString,int>>& data)
    {
        model.setWordCount(data);
    });

    QObject::connect(processor, &FileProcessor::processingHasCancelled, model,
                     [&model]()
    {
        model.cleanModel();
    });
    
    engine.rootContext()->setContextProperty("wordModel", &model);
    engine.rootContext()->setContextProperty("fileProcessor", processor);
    
    engine.load(QUrl(QStringLiteral("qrc:/appView.qml")));
    
    auto roots = engine.rootObjects(); // HARDCODED

    if (roots.isEmpty()) {
        qDebug() << "Engine root Error!!!!";
        return -1;
    }

    auto *root = roots.first(); // Hardcode. Need more flexible decision

    
    QObject::connect(processor, &FileProcessor::progressChanged, root, [=](double value) {
        QMetaObject::invokeMethod(root, "updateProgress", Q_ARG(QVariant, value));
    });
    
    

    QObject::connect(root, SIGNAL(fileHasChosen(QString)), processor,SLOT(setFilePath(QString))); // USE Q_INVOKABLE instead. REMOVE
    QObject::connect(root, SIGNAL(startFileProcessing()), processor,SLOT(startFileProcessing())); // // Use Q_INVOKABLE instead. REMOVE
    

    return app.exec();
}


