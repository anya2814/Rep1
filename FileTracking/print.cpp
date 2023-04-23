#include "print.h"

print::print() {}

// выводится информация об изменении размера файла
void print::printConsoleSize(QString FileName_, qint64 size_)
{
     qDebug() << "I am working";
}

// выводится информация о создании или удалении и изменении размера файла
void print::printConsoleExist(QString FileName_, bool isExist_, qint64 size_)
{
    qDebug() << "I am working";
}
