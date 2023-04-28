#include "print.h"

// выводится начальная информация о файле
void print::addPrintConsole(QString FileName_, bool isExist_, qint64 size_)
{
    if (isExist_)
        qDebug() << FileName_ << " exists, size: " << size_ << ".\n";
    else
        qDebug() << FileName_ << " does not exist.\n";
}

// выводится информация об изменении размера файла
void print::printConsoleSize(QString FileName_, qint64 size_)
{
    qDebug() << FileName_ << " size changed, new size: " << size_ << ". \n";
}

// выводится информация о создании или удалении и изменении размера файла
void print::printConsoleExist(QString FileName_, bool isExist_, qint64 size_)
{
    if (isExist_)
        qDebug() << FileName_ << " was created, size: " << size_ << ".\n";
    else
        qDebug() << FileName_ << " was deleted.\n";
}
