#ifndef PRINT_H
#define PRINT_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QDebug>
#include <filestate.h>

class print : public QObject
{
    Q_OBJECT
    print() {};                      // конструктор по умолчанию
    ~print() {};                  // деструктор
    print& operator= (print) {};   // запрещаем оператор присваивания
    print(const print&) {};     // и конструктор копирования
public:
    static print& InstancePrint() {
        static print receiver;
        return receiver;
    };
public slots:
    void addPrintConsole(QString, bool, qint64);
    void printConsoleSize(QString, qint64);
    void printConsoleExist(QString, bool, qint64);
};

#endif // PRINT_H
