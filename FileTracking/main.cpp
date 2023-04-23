#include <QCoreApplication>

#include <filemonitor.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const int FileCount = 5;
    // задаем список путей для группы из 5(FileCount) файлов
    const QString path[FileCount];
    path[0] = "C:\QtPrograms\files_for_lab1\file1.txt";
    path[1] = "C:\QtPrograms\files_for_lab1\file2.txt";
    path[2] = "C:\QtPrograms\files_for_lab1\file3.txt";
    path[3] = "C:\QtPrograms\files_for_lab1\file4.txt";
    path[4] = "C:\QtPrograms\files_for_lab1\file5.txt";

    // создаем объект класса file monitor
    FileMonitor FilesVector(path, FileCount);
    FilesVector.CheckStatesFiles();

    return a.exec();
}
