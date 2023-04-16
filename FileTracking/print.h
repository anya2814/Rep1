#ifndef PRINT_H
#define PRINT_H

#include <QObject>
#include <filemonitor.h>
#include <filestate.h>

class print : public QObject
{
    int printTo;
public:
    print(printTo = 0);
    void printConsoleSize(int);
    void printConsoleExist(int);
    void connectChangePrint();
};

#endif // PRINT_H
