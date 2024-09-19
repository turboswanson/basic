#pragma once
#include <QVector>
#include <QString>

class myClass
{
public:
    void errorProcessing(const QString error_);
    void getErrorsList();
private:
    QVector<QString> list;

};