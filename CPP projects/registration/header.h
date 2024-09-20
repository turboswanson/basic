#pragma once
#include <QVector>
#include <QString>

class myClass
{
public:
    void errorProcessing(const QString error_);
    bool check(const QString item);
    size_t getListSize();
    QString getItem(size_t index);
private:
    QStringList list_;

};