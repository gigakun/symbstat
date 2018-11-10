#ifndef ARGSPARCER_H
#define ARGSPARCER_H

#include <string>

class IAppConfig
{
public:
    virtual const std::string& GetFileName() const = 0;
    virtual const bool IsIgnoreCPPComments() const = 0;
    virtual ~IAppConfig(){};
};

class ArgsParser : public IAppConfig
{
public:
    ArgsParser(int argc, char* argv[]);
    ~ArgsParser(){};
    const std::string& GetFileName() const override {return m_sFileName;}
    const bool IsIgnoreCPPComments() const override {return m_bIsIgnoreCPPComments;}
private:
    void ParseKeys(char keys[]);
private:
    std::string m_sFileName;
    bool        m_bIsIgnoreCPPComments;
    const std::string m_sInvalidFileName = "";

};

#endif // ARGSPARCER_H
