#include "filestate.h"

FileState::FileState(Qvector<char> filePath_, bool isExist_, qint64_ size_)
{
    filePath = filePath_;
    if (isExist != isExist_) {
        isExist = isExist_;
        size = size_;
        emit valueChangedExist();
    }
    else if (isExist != isExist_) {
        size = size_;
        emit valueChangedSize();
    }
}
