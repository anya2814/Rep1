#include <QCoreApplication>

#include <filemonitor.h>
#include <QString>
#include <print.h>
#include <chrono>
#include <thread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const int FileCount = 5;
    // задаем список путей для группы из 5(FileCount) файлов
    const QString path[FileCount] = {
    "C:/files_for_lab1/file1.txt",
    "C:/files_for_lab1/file2.txt",
    "C:/files_for_lab1/file3.txt",
    "C:/files_for_lab1/file4.txt",
    "C:/files_for_lab1/file5.txt",
    };

    // создаем объект класса file monitor
    FileMonitor FilesVector(path, FileCount);

    //бесконечный цикл проверки файлов (каждые 100 миллисекунд)
    while (true) {
        FilesVector.CheckStatesFiles();
        std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    }
    return a.exec();
}
