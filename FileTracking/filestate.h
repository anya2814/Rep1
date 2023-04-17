#ifndef FILESTATE_H
#define FILESTATE_H

#include <QObject>

class FileState : public QObject
{
    const QString FileName;
    bool isExist;
    qint64 size;
public:
    FileState(QString);
    void SetSize(int);      // для задания размера
    void SetIsExist(bool);  // для задания информации о существовании файла
    QString GetFileName();
    bool GetIsExist();
    qint64 GetSize();
signals:
    void valueChangedSize(qint64);    // сигнал что размер изменен
    void valueChangedExist(bool, qint64);   // сигнал что файл создан или удален
};

#endif // FILESTATE_H
