#ifndef FILEMONITOR_H
#define FILEMONITOR_H


class FileMonitor
{
public:
    FileMonitor();
    void AddFile(QString fileName);
    void DelFile(QString fileName);
    void CheckStatesFiles();
private:
    QVector<FileState> objects;
};

#endif // FILEMONITOR_H
