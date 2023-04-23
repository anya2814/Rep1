#include "filemonitor.h"
#include <QDebug>
#include <QVector>

FileMonitor::FileMonitor() {}

// конструктор с двумя параметрами, константный указатель на массив путей файлов и количество элементов в этом массиве
FileMonitor::FileMonitor(const QString *path, int vectorSize)
{
    objects = QVector<FileState>();
    if (vectorSize > 0)
    for (int i=0; i<vectorSize; i++)
        this->AddFile(path[i]);
}

// добавление файла в группу файлов за которыми следим
// если fileName не пустая строка добавляем объект FileState в вектор
// если вектор уже содержит файл с названием fileName объект FileState не добавляется
void FileMonitor::AddFile(QString fileName)
{
    qDebug() << "ADD";
    int vectorSize = this->objects.size();
    bool flag = 1;
    if (fileName != "" && fileName != NULL)
    {
        FileState FS(fileName);
        for(int i=0; i<vectorSize;i++)
        {
            if ((objects[i]).GetFileName() == fileName)
                flag = 0;
        }
        if (flag) {
            this->objects.append(FS);
            FS.connect();
            emit FS.valueChangedExist(FS.GetFileName(), FS.GetIsExist(), FS.GetSize());
        }
    }
}

// с помощью переменной класса QFileState сохраняем текущее состояние файла, то есть вызываем функцию SetIsExist
// функция SetIsExist проверяет соответствие сохраненных данных с новыми и в случае несоответствия вызывает сигналы об изменении
void FileMonitor::CheckStatesFiles()
{
    int vectorSize = this->objects.size();
    for(int i = 0; i < vectorSize; i++)
    {
        QFileInfo F(objects[i].GetFileName());
        objects[i].connect();
        objects[i].SetIsExist(F.exists(), F.size());
    }
}
