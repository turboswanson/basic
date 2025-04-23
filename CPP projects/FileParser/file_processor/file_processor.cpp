#include "file_processor.h"
#include <QMap>
#include <QRegularExpression>
#include <QTextStream>
#include <QThread>

void FileProcessor::setFilePath(const QString &filepath) {
  this->_filePath = filepath;
}

bool FileProcessor::fileOpening(QFile &file) {
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qDebug() << "FAILED TO OPEN FILE";

    return false;
  }

  return true;
}

void FileProcessor::fileProcessing(QFile &file) {
  int totalLines = 0;
  {
    QTextStream counterStream(&file);
    counterStream.setEncoding(QStringConverter::Utf8);

    while (!counterStream.atEnd()) {
      counterStream.readLine();
      ++totalLines;
    }
  }

  file.seek(0);
  QTextStream stream(&file);
  stream.setEncoding(QStringConverter::Utf8);

  int currentLine = 0;
  while (!stream.atEnd()) {

    if (this->_cancelRequested) {
      emit processingHasCancelled();
      this->_isProcessing = false;
      return;
    }

    QString line = stream.readLine();
    auto matches = this->_wordRegex.globalMatch(line);

    while (matches.hasNext()) {
      auto match = matches.next();
      QString word = match.captured().toLower().trimmed();

      if (!this->_stopWords.contains(word)) {
        this->_matchesCounting[word]++;
      }
    }

    if (currentLine % updateInterval == 0 || currentLine == totalLines - 1) {
      emit progressChanged(static_cast<double>(currentLine + 1) / totalLines);
    }

    ++currentLine;
  }
}

void FileProcessor::resultSorting() {
  this->_result.clear();

  for (auto it = this->_matchesCounting.constBegin();
       it != this->_matchesCounting.constEnd(); ++it) {
    this->_result.append(qMakePair(it.key(), it.value()));
  }

  std::sort(this->_result.begin(), this->_result.end(),
            [](const auto &a, const auto &b) { return b.second < a.second; });

  this->_result = this->_result.mid(0, wordsLimit);

  emit fileProcessed(this->_result);
}

void FileProcessor::startFileProcessing() {
  qDebug() << "startFileProcessing() thread:" << QThread::currentThread();
  this->_cancelRequested = false;

  if (this->_isProcessing) {
    qDebug() << "It's already in use";
    return;
  }

  this->_isProcessing = true;

  this->_matchesCounting.clear();

  QFile file(this->_filePath);

  if (!this->fileOpening(file)) {
    return;
  }

  this->fileProcessing(file);

  this->resultSorting();

  file.close();
}

void FileProcessor::cancelFileProcessing() {
  {
    this->_cancelRequested = true;
    this->_isProcessing = false;
    emit processingHasCancelled();
  }
}

void FileProcessor::clearData() {
  this->_matchesCounting.clear();
  this->_result.clear();
  this->_filePath.clear();
}
