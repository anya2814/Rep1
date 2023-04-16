#include "print.h"

print::print(int printTo_)
{
    printTo = printTo;
}

void connectChangePrint() {
QObject::connect(& objects, SIGNAL(valueChanged()),
                     &printTo, SLOT(printToConsole()));
}

void printToConsole();
