#ifndef FILESTATE_H
#define FILESTATE_H

#include <QObject>
#include <QString>
#include <QFileInfo>
#include <print.h>

class FileState : public QObject
{
    Q_OBJECT
    QString FileName;     // путь файла
    bool isExist;               // существует или не существует файл
    qint64 size;                // размер файла
public:
    FileState();                    // конструктор по умолчанию
    FileState(const QString);         // конструктор класса
    void Update();      // для обновления информации о существовании файла и размера или размера
    QString GetFileName();      // для получения FileName
    bool GetIsExist();          // для получения isExist
    qint64 GetSize();           // для получения size
    FileState& operator= (FileState);   // оператор присваивания
    FileState(const FileState&);     // конструктор копирования
signals:
    void addSignalPrintConsole(QString, bool, qint64); // начальная информация о файле
    void valueChangedSize(QString, qint64);    // сигнал что размер изменен
    void valueChangedExist(QString, bool, qint64);   // сигнал что файл создан или удален
};

#endif // FILESTATE_H
