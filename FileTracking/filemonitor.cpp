#include "filemonitor.h"

// конструктор по умолчанию
FileMonitor::FileMonitor()
{
    objects = QVector<FileState>();
}

// конструктор в который подается QVector<QString>
/*FileMonitor::FileMonitor(const QVector<QString> path)
{
    objects = QVector<FileState>();
    int vectorSize = path.size();
    if (!path.isEmpty())
    for (int i=0; i < vectorSize; i++)
        AddFile(path[i]);
}*/

// добавление файла в группу файлов за которыми следим
// если fileName не пустая строка добавляем объект FileState в вектор
// если вектор уже содержит файл с названием fileName объект FileState не добавляется
void FileMonitor::AddFile(QString fileName)
{
    int vectorSize = objects.size();
    bool flag = 1;
    if (fileName != "")
    {
        for(int i=0; i < vectorSize; i++)
        {
            if ((objects[i]).GetFileName() == fileName)
                flag = 0;
        }
        if (flag) {
            FileState FS(fileName);
            objects.append(FS);
            emit FS.addSignalPrintConsole(FS.GetFileName(), FS.GetIsExist(), FS.GetSize());
        }
    }
}

// удаление файла с путем fileName
void FileMonitor::DelFile(QString fileName)
{
    int vectorSize = objects.size();
    for(int i=0; i < vectorSize; i++)
    {
        if ((objects[i]).GetFileName() == fileName) {
            objects.remove(i);
            i = vectorSize;
        }
    }
}

// с помощью переменной класса QFileState сохраняем текущее состояние файла, то есть вызываем функцию SetIsExist
// функция SetIsExist проверяет соответствие сохраненных данных с новыми и в случае несоответствия вызывает сигналы об изменении
void FileMonitor::CheckStatesFiles()
{
    int vectorSize = objects.size();
    for(int i = 0; i < vectorSize; i++)
        objects[i].Update();
}
