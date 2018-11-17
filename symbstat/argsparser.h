#ifndef ARGSPARCER_H
#define ARGSPARCER_H

#include <string>

class IAppConfig
{
public:
    virtual const std::string& GetFileName() const = 0;
    virtual bool IsIgnoreCPPComments() const = 0;
    virtual ~IAppConfig();
};

class ArgsParser : public IAppConfig
{
public:
    ArgsParser(int argc, char* argv[]);
    ~ArgsParser() override;
private:
	// Implementation of IAppConfig
	const std::string& GetFileName() const override { return m_sFileName; }
    bool IsIgnoreCPPComments() const override { return m_bIsIgnoreCPPComments; }

    void ParseKeys(char keys[]);
private:
    std::string m_sFileName;
    bool        m_bIsIgnoreCPPComments;
    const std::string m_sInvalidFileName = "";

};

#endif // ARGSPARCER_H
