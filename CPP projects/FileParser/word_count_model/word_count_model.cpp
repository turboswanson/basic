#include "word_count_model.h"

WordCountModel::WordCountModel(QObject *parent) : QAbstractListModel(parent) {}

int WordCountModel::rowCount(const QModelIndex &index) const {
  return this->_wordCounts.size();
}

QVariant WordCountModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid() || index.row() > this->rowCount()) {
    return QVariant();
  }

  const auto &tmpPair = this->_wordCounts[index.row()];
  if (role == WordRole)
    return tmpPair.first;
  if (role == CountRole)
    return tmpPair.second;

  return QVariant();
}

QHash<int, QByteArray> WordCountModel::roleNames() const {
  return this->_roleNames;
}

void WordCountModel::setWordCount(const QVector<QPair<QString, int>> &data) {
  beginResetModel();
  this->_wordCounts = data;
  endResetModel();

  emit countChanged();
}

int WordCountModel::getMaxCount() {
  int max = 0;

  for (auto &pair : this->_wordCounts) {
    if (pair.second > max)
      max = pair.second;
  }

  return max;
}

void WordCountModel::cleanModel() {
  beginResetModel();
  this->_wordCounts.clear();
  endResetModel();

  emit countChanged();
}
