#include "filemonitor.h"

FileMonitor::FileMonitor(int vectorSize = 0)
{
    objects = QVector<FileState>();
    QString FilePath();
    if (vectorSize >= 0)
    for (int i=0; i<vector; i++)
    {
        cout << "Enter a file's path: ";
        FilePath = cin.readLine();
        *this->AddFile(FilePath);
    }
}

void FileMonitor::AddFile(QString fileName)     // добавление файла в группу файлов за которыми следим
{
    if (filename!="")
    {
        FileState F(fileName);
        if (!(*this->contains(&F)))
                *this->append(&F);
                else cout << "File with path: " << fileName << " is already in the list." << endl;
    }
}

void FileMonitor::DelFile(QString fileName)
{
    FileState F(fileName);
    objects.removeOne(&F);
}

void FileMonitor::CheckStatesFiles()
{
    bool f = 1;
    while (f)
    {
        for(int i = 0; i<ObjectsSize; i++)
        {
            QFileInfo F(objects[i].GetFileName());
            if (objects[i].GetIsExist() != F.exists())
                objects[i].SetIsExist((objects[i].GetIsExist()), F.size());
            else if (objects[i].GetSize() != F.size())
                objects[i].SetSize(F.size());
        }
    if (event->key()) f = 0;
    }
}
