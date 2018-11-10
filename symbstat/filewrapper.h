#ifndef FILEWRAPPER_H
#define FILEWRAPPER_H

#include <string>
#include <fstream>

class FileWrapper
{
public:
    FileWrapper(const std::string &filePath);
    ~FileWrapper();
    bool GetChar(char& ch);
private:
    std::ifstream m_file;
};

#endif // FILEWRAPPER_H
