#pragma once

#include <QObject>
#include <QMap>
#include <QFile>
#include <QRegularExpression>

inline constexpr int wordsLimit = 15;
inline constexpr int updateInterval = 10;

class FileProcessor : public QObject
{
    Q_OBJECT
public:
    explicit FileProcessor(QObject *parent = nullptr);

    Q_INVOKABLE void setFilePath(const QString& filepath);
    Q_INVOKABLE void startFileProcessing();
    Q_INVOKABLE void cancelFileProcessing();
private:
    bool fileOpening(QFile& file);
    bool fileProcessing(QFile& file);
    void resultSorting();
    void clearData();
signals:
    void fileProcessed(QVector<QPair<QString,int>> wordCounts);
    void processingHasCancelled();
    void progressChanged(double progress);
private:
    QString _filePath;

    inline static const QRegularExpression _wordRegex =
       QRegularExpression("[\\p{L}]{2,}", QRegularExpression::CaseInsensitiveOption);
    inline static const QSet<QString> _stopWords = {

        "a", "an", "and", "are", "as", "at", "be", "been", "but",
        "by", "for", "from", "has", "have", "if", "in", "is", "it",
        "of", "on", "or", "that", "the", "to", "was", "were", "with",

        "в", "во", "на", "по", "при", "у", "к", "из", "из-за", "от", "до", "за",
        "и", "но", "а", "не", "что", "как", "же", "ли", "т.д"
    };

     QMap<QString,int> _matchesCounting;
     QVector<QPair<QString,int>> _result;
     bool _isProcessing = false;
     std::atomic<bool> _cancelRequested = false;
};
