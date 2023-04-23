#ifndef PRINT_H
#define PRINT_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QDebug>
#include <filemonitor.h>

class print : public QObject
{
    Q_OBJECT
public:
    print();
    void connectChangePrint();
    print(int printTo_);
public slots:
    void printConsoleSize(QString, qint64);
    void printConsoleExist(QString, bool, qint64);
};

#endif // PRINT_H
