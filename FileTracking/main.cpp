#include <QCoreApplication>

#include <filemonitor.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // создаем объект класса file monitor
    FileMonitor FilesVector();
    return a.exec();
}
