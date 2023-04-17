#include "print.h"

print::print(int printTo_)
{
    printTo = printTo;
}

void connectChangePrint() {
    QObject::connect(& objects, SIGNAL(valueChangedSize(size)),
                     &printTo, SLOT(printConsoleSize(size)));
    QObject::connect(& objects, SIGNAL(valueChangedExist(isExist, size)),
                         &printTo, SLOT(printConsoleExist(isExist, size)));
}

// выводится информация об изменении размера файла
void printConsoleSize() {

}

// выводится информация о создании или удалении и изменении размера файла
void printConsoleExist() {

}
