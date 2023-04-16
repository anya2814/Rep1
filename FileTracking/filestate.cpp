#include "filestate.h"

FileState::FileState(Qvector<char> filePath_, bool isExist_, qint64_ size_)
{
    filePath = filePath_;
    isExist ;
    size = size_;
}
