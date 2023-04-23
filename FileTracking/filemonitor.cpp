#include "filemonitor.h"
#include <QDebug>
#include <QVector>

// конструктор с двумя аргументами по умолчанию, входные параметры это константный указатель на массив путей файлов и количество элементов в этом массиве
FileMonitor::FileMonitor(const QString *path = nullptr, int vectorSize = 0)
{
    objects = QVector<FileState>();
    if (vectorSize > 0)
    for (int i=0; i<vectorSize; i++)
        this->AddFile(path[i]);
}

// оператор присваивания
/*
FileMonitor& FileMonitor::operator = (FileMonitor A)
{
    this->objects = A.objects;
    return *this;
}

// конструктор копирования
FileMonitor::FileMonitor(const FileMonitor& A)
{
    this->objects = A.objects;
}
*/
// добавление файла в группу файлов за которыми следим
// если fileName не пустая строка добавляем объект FileState в вектор
// если вектор уже содержит файл с названием fileName объект FileState не добавляется
//
void FileMonitor::AddFile(QString fileName)
{
    qDebug() << "ADD";
    if (fileName!="" && fileName!=nullptr)
    {
        FileState FS(fileName);
       // if (!(this->objects.contains(FS))) {
            this->objects.append(FS);
            emit FS.valueChangedExist(FS.GetIsExist(), FS.GetSize());
      //  }
        //else cout << "File with path: " << fileName << " is already in the list." << endl;
    }
}

/*// удаляем один файл с именем fileName, больше 1 файла с таким именем в векторе быть не должно
void FileMonitor::DelFile(QString fileName)
{
    objects.removeOne(&(*this));
}*/

// с помощью переменной класса QFileState сохраняем текущее состояние файла, то есть вызываем функцию SetIsExist
// функция SetIsExist проверяет соответствие сохраненных данных с новыми и в случае несоответствия вызывает сигналы об изменении
void FileMonitor::CheckStatesFiles(int vectorSize)
{
    bool f = 1;
    while (f)
    {
        for(int i = 0; i<vectorSize; i++)
        {
            QFileInfo F(objects[i].GetFileName());
            objects[i].SetIsExist((objects[i].GetIsExist()), F.size());
        }
    //if (event->key()) f = 0;        // если пользователь нажимает какую-либо клавишу, бесконечный цикл прерывается
    }
}
