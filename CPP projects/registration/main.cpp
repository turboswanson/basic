#include "header.h"
#include <QTranslator>
#include <QApplication>
#include <iostream>
#include <QVector>

int main(int argc,char *argv[]){

    QApplication app(argc,argv);
    QStringList list;
    list << "first ";
    list << "second ";
    list << "third ";
    QString last = list.takeLast();
    QString tmp = list.join(", ") + "and " + last;
    
    // for(auto i = 0; i < list.size(); i++)
    // {
        qDebug() <<tmp;
    // }

    



    return 0;
}