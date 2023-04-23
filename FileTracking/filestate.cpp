#include "filestate.h"

// конструктор с одним параметром по умолчанию
// из параметра получаем путь к файлу, создаем переменную temp класса QFileInfo и с помощью методов этого класса получаем информацию о файле
FileState::FileState(QString<char> FileName_ = nullptr)
{
    FileName = FileName_;
    QFileInfo F(const &FileName_);
    isExist = F.exists();
    size = F.size();
}

// если поданное в функцию значение о существовании файла не совпадает с сохраненным, записываем новое значение и срабатывает сигнал
// иначе вызываем функцию SetSize
void FileState::SetIsExist(bool isExist_, qint64 size_)
{
    if (isExist != isExist_) {
        isExist = isExist_;
        size = size_;
        emit valueChangedExist(isExist, size);
    }
    else SetSize(size_);
}

// если поданное в функцию значение о размере файла не совпадает с сохраненным, записываем новое значение и срабатывает сигнал
void FileState::SetSize(qint64 size_)
{
    if (size != size_) {
        size = size_;
        emit valueChangedSize(size);
    }
}

// функция возвращает значение FileName
QString GetFileName()
{
    return *this->FileName;
}

// функция возвращает значение isExist
bool GetIsExist()
{
    return *this->isExist;
}

// функция возвращает значение size
qint64 GetSize()
{
    return *this->size;
}
