#include "filestate.h"

// конструктор по умолчанию
FileState::FileState(){
    FileName = QString();
    isExist = false;
    size = 0;
    print& receiver = print::InstancePrint();
    QObject::connect(this, &FileState::addSignalPrintConsole,
                     &receiver, &print::addPrintConsole);
    QObject::connect(this, &FileState::valueChangedSize,
                     &receiver, &print::printConsoleSize);
    QObject::connect(this, &FileState::valueChangedExist,
                     &receiver, &print::printConsoleExist);
}

// конструктор с одним параметром по умолчанию
// из параметра получаем путь к файлу, создаем переменную temp класса QFileInfo и с помощью методов этого класса получаем информацию о файле
FileState::FileState(const QString FileName_)
{
    FileName = FileName_;
    QFileInfo F(FileName_);
    isExist = F.exists();
    size = F.size();
    print& receiver = print::InstancePrint();
    QObject::connect(this, &FileState::addSignalPrintConsole,
                     &receiver, &print::addPrintConsole);
    QObject::connect(this, &FileState::valueChangedSize,
                     &receiver, &print::printConsoleSize);
    QObject::connect(this, &FileState::valueChangedExist,
                     &receiver, &print::printConsoleExist);
}

//оператор присваивания
FileState& FileState::operator = (FileState A)
{
    FileName = A.FileName;
    isExist = A.isExist;
    size = A.size;
    return *this;
}

// конструктор копирования
FileState::FileState(const FileState& A)
{
    FileName = A.FileName;
    isExist = A.isExist;
    size = A.size;
    print& receiver = print::InstancePrint();
    QObject::connect(this, &FileState::addSignalPrintConsole,
                     &receiver, &print::addPrintConsole);
    QObject::connect(this, &FileState::valueChangedSize,
                     &receiver, &print::printConsoleSize);
    QObject::connect(this, &FileState::valueChangedExist,
                     &receiver, &print::printConsoleExist);
}

// обновление информации о файле
void FileState::Update()
{
    QFileInfo F(FileName);
    if (isExist != F.exists()) {
        isExist = F.exists();
        size = F.size();
        emit this->valueChangedExist(FileName, isExist, size);
    }
    else if(size != F.size()) {
        size = F.size();
        emit this->valueChangedSize(FileName, size);
    }
}

// функция возвращает значение FileName
QString FileState::GetFileName()
{
    return FileName;
}

// функция возвращает значение isExist
bool FileState::GetIsExist()
{
    return isExist;
}

// функция возвращает значение size
qint64 FileState::GetSize()
{
    return size;
}
