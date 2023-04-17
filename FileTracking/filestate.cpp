#include "filestate.h"

// конструктор с тремя агументами по умолчанию
FileState::FileState(QString<char> FileName_ = nullptr)
{
    FileName = FileName_;
    QFileInfo temp(const &FileName_);
    isExist = temp.exists();
    size = temp.size();
    if (FileName != nullptr)
        emit valueChangedExist(isExist, size);
}

void FileState::SetIsExist(bool isExist_, qint64 size_)
{
    if (isExist != isExist_) {
        isExist = isExist_;
        size = size_;
        emit valueChangedExist(isExist, size);
    }
}

void FileState::SetSize(bool isExist_)
{
    if (isExist != isExist_) {
        isExist = isExist_;
        size = size_;
        emit valueChangedSize(size);
    }
}
