#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QFileInfo>
#include <filestate.h>
#include <print.h>

class FileMonitor
{
    QVector<FileState> objects;         // вектор объектов класса FileState, в которых хранится путь к файлу и его состояние (существует, размер)
    FileMonitor() {};                      // конструктор по умолчанию
    FileMonitor(const QString*, const int);         // конструктор класса
    ~FileMonitor() {};                  // деструктор
    FileMonitor& operator= (FileMonitor) {};   // запрещаем оператор присваивания
    FileMonitor(const FileMonitor&) {};     // и конструктор копирования
public:
    static FileMonitor& Instance(const QString* path, const int vectorSize) {
        static FileMonitor FM(path, vectorSize);
        return FM;
    };
    void AddFile(QString fileName);     // добавление файла в группу файлов за которыми следим
    void CheckStatesFiles();        // проверка состояний файлов, если файл был изменен,
                                        // то нам нужно сохранить новую информацию о нем в объекте и вывести на экран сообщение о том что файл был изменен
};

#endif // FILEMONITOR_H
