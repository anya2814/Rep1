#include "print.h"

print::print(int printTo_)
{
    printTo = printTo;
}

void connectChangePrint() {
    QObject::connect(& objects, SIGNAL(valueChangedSize()),
                     &printTo, SLOT(printConsoleSize()));
    QObject::connect(& objects, SIGNAL(valueChangedExist()),
                         &printTo, SLOT(printConsoleExist()));
}

// выводится информация об изменении размера файла
void printConsoleSize() {

}

// выводится информация о создании или удалении и изменении размера файла
void printConsoleExist() {

}
