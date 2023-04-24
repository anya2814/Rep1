#include <QCoreApplication>

#include <filemonitor.h>
#include <QString>
#include <print.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const int FileCount = 5;
    // задаем список путей для группы из 5(FileCount) файлов
    const QString path[FileCount] = {
    "C:\\QtPrograms\files_for_lab1\file1.txt",
    "C:\\QtPrograms\files_for_lab1\file2.txt",
    "C:\\QtPrograms\files_for_lab1\file3.txt",
    "C:\\QtPrograms\files_for_lab1\file4.txt",
    "C:\\QtPrograms\files_for_lab1\file5.txt",
    };

    // создаем объект класса file monitor
    FileMonitor FilesVector(path, FileCount);

    // функция соединения сигналов и слотов
    FilesVector.connectChange();

    //бесконечный цикл проверки файлов
    while (true)
        FilesVector.CheckStatesFiles();

    return a.exec();
}
