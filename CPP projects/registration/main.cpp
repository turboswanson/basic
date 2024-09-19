#include "header.h"
#include <QTranslator>
#include <QApplication>
#include <iostream>
#include <QVector>

int main(int argc,char *argv[]){

    QApplication app(argc,argv);
    myClass obj;
    QVector<QString> errors = {"nickname","phone","email"};
    
    int num = 3;

    for(auto i = 0; i < num ; i++)
    {
        obj.errorProcessing(errors.at(i));
    }

    obj.getErrorsList();

    return 0;
}