#include "argsparser.h"
#include <sstream>

static const std::string sClassName = "ArgsParser";

ArgsParser::ArgsParser(int argc, char* argv[])
    : m_sFileName("")
    , m_bIsIgnoreCPPComments(false)
{
    for(int i = 1; i < argc; ++i)
    {
        if(argv[i][0] == '-')
        {
            ParseKeys(argv[i]);
        }
        else
        {
            m_sFileName = std::string(argv[i]);
        }
    }
    if(m_sFileName == m_sInvalidFileName)
    {
        throw std::string(sClassName + ": Invalid format! Couldn't parse filename!");
    }
}

void ArgsParser::ParseKeys(char keys[])
{
    for(size_t i = 1; keys[i] != '\0'; ++i)
    {
        switch(keys[i])
        {
        case 'c':
            m_bIsIgnoreCPPComments = true;
            break;
        default:
            throw std::string(sClassName + ": Unknown key! Key: " + keys[i]);
        }
    }
}
