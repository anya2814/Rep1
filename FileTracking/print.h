#ifndef PRINT_H
#define PRINT_H

#include <QObject>
#include <filemonitor.h>

class print : public QObject
{
public:
    void connectChangePrint();
public slots:
    void printConsoleSize(int);
    void printConsoleExist(int);
};

#endif // PRINT_H
