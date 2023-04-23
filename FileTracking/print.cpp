#include "print.h"
#include <QDebug>

print::print(int printTo_)
{
    //printTo = printTo;
}
print::print(){

}
void print::connectChangePrint() {

}

// выводится информация об изменении размера файла
void print::printConsoleSize(qint64) {

  //  bool sizeNew = F.GetSize();
     qDebug() << "I am working";
}

// выводится информация о создании или удалении и изменении размера файла
void print::printConsoleExist(bool, qint64) {
 qDebug() << "I am working";
}
