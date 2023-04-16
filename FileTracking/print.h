#ifndef PRINT_H
#define PRINT_H

#include <QObject>
#include <filemonitor.h>
#include <filestate.h>

// printTo = 0 если выводим на консоль
class print : public QObject
{
    int printTo;
public:
    print(printTo = 0);
    void printToConsole();
    void connectChangePrint();
};

#endif // PRINT_H
