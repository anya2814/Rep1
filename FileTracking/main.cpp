#include <QCoreApplication>

#include <filemonitor.h>
#include <QString>
#include <QVector>
#include <chrono>
#include <thread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // задаем список путей для группы из 5(FileCount) файлов
    const QVector<QString> path = {
    "C:/files_for_lab1/file1.txt",
    "C:/files_for_lab1/file1.txt",
    "C:/files_for_lab1/file3.txt",
    "C:/files_for_lab1/file4.txt",
    "C:/files_for_lab1/file5.txt",
    };

    // создаем объект класса file monitor
    FileMonitor& instance = FileMonitor::Instance();
    for(int i = 0; i < path.size(); i++)
        instance.AddFile(path[i]);

    // тест
    instance.AddFile("C:/files_for_lab1/file6.txt");
    bool flag = true;

    //бесконечный цикл проверки файлов (каждые 100 миллисекунд)
    while (true) {
        // тест
        if (flag) {
            instance.DelFile("C:/files_for_lab1/file5.txt");
            flag = false;
        }
        instance.CheckStatesFiles();
        std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    }

    return a.exec();
}
