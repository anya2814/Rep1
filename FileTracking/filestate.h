#ifndef FILESTATE_H
#define FILESTATE_H

#include <QObject>
#include <QString>
#include <QFileInfo>

class FileState : public QObject
{
    Q_OBJECT
    QString FileName;     // путь файла
    bool isExist;               // существует или не существует файл
    qint64 size;                // размер файла
public:
    FileState();
    FileState(const QString);         // конструктор класса
    void SetSize(qint64);          // для задания размера
    void SetIsExist(bool, qint64);      // для задания информации о существовании файла
    QString GetFileName();      // для получения FileName
    bool GetIsExist();          // для получения is
    qint64 GetSize();
    FileState& operator= (FileState);   // оператор присваивания
    bool operator== (const FileState&);
    FileState(const FileState&);     // конструктор копирования
signals:
    void valueChangedSize(qint64);    // сигнал что размер изменен
    void valueChangedExist(bool, qint64);   // сигнал что файл создан или удален
};

#endif // FILESTATE_H
