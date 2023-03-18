#ifndef FILESTATE_H
#define FILESTATE_H

#include <Qstring>


class FileState
{
    Qstring FileName;
    bool isExist;
    qint64 size;
public:
    FileState(Qstring<char> filePath = null, bool = false, qint64 = 0);
};

#endif // FILESTATE_H
