#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QFileInfo>
#include <filestate.h>
#include <print.h>

class FileMonitor : QObject
{
    Q_OBJECT
    QVector<FileState> objects;         // вектор объектов класса FileState, в которых хранится путь к файлу и его состояние (существует, размер)
public:
    FileMonitor();                      // конструктор по умолчанию
    FileMonitor(const QString *path, int vectorSize);         // конструктор класса
    void AddFile(QString fileName);     // добавление файла в группу файлов за которыми следим
    void CheckStatesFiles();        // проверка состояний файлов, если файл был изменен,
                                        // то нам нужно сохранить новую информацию о нем в объекте и вывести на экран сообщение о том что файл был изменен
    void connectChange();             // функция для соединения сигналов и слотов
};

#endif // FILEMONITOR_H
