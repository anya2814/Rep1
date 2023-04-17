#ifndef FILESTATE_H
#define FILESTATE_H

#include<QString>

class FileState : public QObject
{
    Qstring<char> FileName;
    bool isExist;
    qint64 size;
public:
    FileState(Qstring<char>);
    void SetSize(int);      // для задания размера
    void SetIsExist(bool);  // для задания информации о существовании файла
signals:
    void valueChangedSize(size);    // сигнал что размер изменен
    void valueChangedExist(isExist, size);   // сигнал что файл создан или удален
};

#endif // FILESTATE_H
