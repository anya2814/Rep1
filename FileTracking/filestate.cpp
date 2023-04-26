#include "filestate.h"
#include "print.h"

// конструктор по умолчанию
FileState::FileState(){
    FileName = nullptr;
    isExist = false;
    size = 0;
}

// конструктор с одним параметром по умолчанию
// из параметра получаем путь к файлу, создаем переменную temp класса QFileInfo и с помощью методов этого класса получаем информацию о файле
FileState::FileState(const QString FileName_)
{
    FileName = FileName_;
    QFileInfo F(FileName_);
    isExist = F.exists();
    size = F.size();
    print *receiver = new print;
    QObject::connect(this, &FileState::addSignalPrintConsole,
                     receiver, &print::addPrintConsole);
    QObject::connect(this, &FileState::valueChangedSize,
                     receiver, &print::printConsoleSize);
    QObject::connect(this, &FileState::valueChangedExist,
                     receiver, &print::printConsoleExist);
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
    print *receiver = new print;
    QObject::connect(this, &FileState::addSignalPrintConsole,
                     receiver, &print::addPrintConsole);
    QObject::connect(this, &FileState::valueChangedSize,
                     receiver, &print::printConsoleSize);
    QObject::connect(this, &FileState::valueChangedExist,
                     receiver, &print::printConsoleExist);
}

// если поданное в функцию значение о существовании файла не совпадает с сохраненным, записываем новое значение и срабатывает сигнал
// иначе вызываем функцию SetSize
void FileState::SetIsExist(bool isExist_, qint64 size_)
{
    if (isExist != isExist_) {
        isExist = isExist_;
        size = size_;
        emit this->valueChangedExist(FileName, isExist, size);
    }
    else SetSize(size_);
}

// если поданное в функцию значение о размере файла не совпадает с сохраненным, записываем новое значение и срабатывает сигнал
void FileState::SetSize(qint64 size_)
{
    if (size != size_) {
        size = size_;
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
