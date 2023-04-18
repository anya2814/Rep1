#include "print.h"

print::print(int printTo_)
{
    printTo = printTo;
}

void print::connectChangePrint() {
    QObject::connect(& objects, SIGNAL(valueChangedSize(size)),
                     &printTo, SLOT(printConsoleSize(size)));
    QObject::connect(& objects, SIGNAL(valueChangedExist(isExist, size)),
                         &printTo, SLOT(printConsoleExist(isExist, size)));
}

// выводится информация об изменении размера файла
void print::printConsoleSize(FileState *F) {
    bool sizeNew = F.GetSize()
}

// выводится информация о создании или удалении и изменении размера файла
void print::printConsoleExist() {

}
