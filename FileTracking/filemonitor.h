#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <Qobject>

class FileMonitor : public QObject
{
    Q_OBJECT
public:
    FileMonitor(QVector<FileState> objects = NULL);
    void AddFile(QString fileName);     // добавление файла в группу файлов за которыми следим
    void DelFile(QString fileName);     // удаление файла из группы
public slots:
    void CheckStatesFiles();    // проверка состояний файлов
signals:
    void FileChanged();
private:
    QVector<FileState> objects;     // вектор объектов класса FileState, в которых хранится путь к файлу и его состояние (существует, размер)
};

#endif // FILEMONITOR_H
