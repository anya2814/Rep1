#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QFileInfo>
#include <filestate.h>

class FileMonitor
{
    QVector<FileState> objects;         // вектор объектов класса FileState, в которых хранится путь к файлу и его состояние (существует, размер)
public:
    FileMonitor(const QString *path, int vectorSize);         // конструктор класса
    void AddFile(QString fileName);     // добавление файла в группу файлов за которыми следим
//    void DelFile(QString fileName);     // удаление файла из группы
    void CheckStatesFiles(int vectorSize);        // проверка состояний файлов, если файл был изменен,
                                        // то нам нужно сохранить новую информацию о нем в объекте и вывести на экран сообщение о том что файл был изменен
  // FileMonitor& operator = (FileMonitor);   // оператор присваивания
  // FileMonitor(const FileMonitor&);     // конструктор копирования
};

#endif // FILEMONITOR_H
