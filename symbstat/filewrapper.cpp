#include "filewrapper.h"

FileWrapper::FileWrapper(const std::string &filePath)
    :m_file(filePath)
{
    if(!m_file.is_open())
    {
        throw std::string("Couldn't open file");
    }
}
FileWrapper::~FileWrapper()
{
    m_file.close();
}
bool FileWrapper::GetChar(char& ch)
{
    bool result = false;
    if(m_file >> ch)
    {
        result = true;
    }
    return result;
}
