#ifndef FILESTATE_H
#define FILESTATE_H

class FileState
{
    Qstring FileName;
    bool isExist;
    qint64 size;
public:
    FileState(Qstring<char> filePath = nullptr, bool isExist = false, qint64 size = 0);
};

#endif // FILESTATE_H
