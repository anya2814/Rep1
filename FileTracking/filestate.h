#ifndef FILESTATE_H
#define FILESTATE_H

#include <QObject>

class FileState : public QObject
{
    const QString FileName;     // путь файла
    bool isExist;               // существует или не существует файл
    qint64 size;                // размер файла
public:
    FileState(QString);         // конструктор класса
    void SetSize(int);          // для задания размера
    void SetIsExist(bool);      // для задания информации о существовании файла
    QString GetFileName();      // для получения FileName
    bool GetIsExist();          // для получения is
    qint64 GetSize();
signals:
    void valueChangedSize(qint64);    // сигнал что размер изменен
    void valueChangedExist(bool, qint64);   // сигнал что файл создан или удален
};

#endif // FILESTATE_H
