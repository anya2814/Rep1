#ifndef PRINT_H
#define PRINT_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QDebug>
#include <filemonitor.h>
#include <filestate.h>

class print : public QObject
{
    Q_OBJECT
public:
    print();
public slots:
    void addPrintConsole(QString, bool, qint64);
    void printConsoleSize(QString, qint64);
    void printConsoleExist(QString, bool, qint64);
};

#endif // PRINT_H
