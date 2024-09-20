#include "header.h"
#include <iostream>
#include <QDebug>


void myClass::errorProcessing(const QString error_)
{
    this->list_.append(error_);
}

bool myClass::check(const QString item)
{
    return this->list_.contains(item);
}

size_t myClass::getListSize()
{
    return this->list_.size();
}

QString myClass::getItem(size_t index)
{
    return this->list_.at(index);
}