#include "header.h"
#include <QTranslator>
#include <QApplication>
#include <iostream>
#include <QVector>

int main(int argc,char *argv[]){

    QApplication app(argc,argv);
    myClass obj;
    QVector<QString> errors = {"никнейм","телефон","email"};
    
    int num = 3;

    for(auto i = 0; i < num ; i++)
    {
        obj.errorProcessing(errors.at(i));
    }

    QString result = "Ошибка регистрации. Неверный ";

    for(size_t i = 0; i < obj.getListSize();i++)
    {
        result += obj.getItem(i);

        if(obj.getListSize() > 1 && i < obj.getListSize()-1)
        {
            result += ", ";
        }

        if(i == obj.getListSize()-1) result += "." ;   
    }

    qCritical() << obj.getListSize();    


    return 0;
}