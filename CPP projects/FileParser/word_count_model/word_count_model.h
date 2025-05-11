#pragma once

#include <QAbstractListModel>

enum Roles
{
    WordRole = Qt::UserRole+1,
    CountRole
};

class WordCountModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int rowCount READ rowCount NOTIFY countChanged)
    Q_PROPERTY(int maxCount READ getMaxCount NOTIFY countChanged)
signals:
    void countChanged();
public:
    WordCountModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    void setWordCount(const QVector<QPair<QString,int>>& data);
    int getMaxCount();
    Q_INVOKABLE void cleanModel();

private:
    QVector<QPair<QString,int>> _wordCounts;
    QHash<int, QByteArray> _roleNames {{WordRole,"word"},
                                        {CountRole,"count"}};
};
