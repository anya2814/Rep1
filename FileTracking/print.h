#ifndef PRINT_H
#define PRINT_H

#include <QObject>
#include <filemonitor.h>
#include <filestate.h>

class print : public QObject
{
public:
    void printConsoleSize(int);
    void printConsoleExist(int);
    void connectChangePrint();
};

#endif // PRINT_H
