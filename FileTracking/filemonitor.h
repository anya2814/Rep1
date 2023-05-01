#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QVector>
#include <QFileInfo>
#include <QDebug>
#include <filestate.h>
#include <print.h>

class FileMonitor
{
    QVector<FileState> objects;         // вектор объектов класса FileState, в которых хранится путь к файлу и его состояние (существует, размер)
    FileMonitor();                      // конструктор по умолчанию
    FileMonitor(const QVector<QString>);         // конструктор класса
    ~FileMonitor() {};                  // деструктор
    FileMonitor& operator= (FileMonitor) {};   // запрещаем оператор присваивания
    FileMonitor(const FileMonitor&) {};     // и конструктор копирования
public:
    static FileMonitor& Instance(const QVector<QString> path) {
        static FileMonitor FM(path);
        return FM;
    };
    void AddFile(QString fileName);     // добавление файла в группу файлов за которыми следим
    void DelFile(QString fileName);     // удаление файла из группы
    void CheckStatesFiles();        // проверка состояний файлов, если файл был изменен,
                                        // то нам нужно сохранить новую информацию о нем в объекте и вывести на экран сообщение о том что файл был изменен
};

#endif // FILEMONITOR_H
