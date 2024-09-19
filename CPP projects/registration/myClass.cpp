#include "header.h"
#include <iostream>


void myClass::errorProcessing(const QString error_)
{
    this->list << error_;
}

void myClass::getErrorsList()
{
    for(auto i : this->list)
        std::cout << i.toStdString() << std::endl;
}