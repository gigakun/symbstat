#include <iostream>
#include <cstdint>
#include <map>
#include <string>
#include <fstream>
#include <memory>

#include "filewrapper.h"
#include "argsparser.h"

int main(int argc, char *argv[])
{
    try {
        std::unique_ptr<IAppConfig> config(new ArgsParser(argc, argv));


        FileWrapper file(config->GetFileName());
        char currentSymbol;
        std::map<char, uint64_t> symbolMatchCounter;
        while(file.GetChar(currentSymbol))
        {
            symbolMatchCounter[currentSymbol]++;
        }
        for(auto symbStat : symbolMatchCounter)
        {
            std::cout << " Sym: " << symbStat.first << "\t\t " << symbStat.second << std::endl;
        }

    }
    catch (std::string e)
    {
        std::cout << "Exception: " << e << std::endl;
    }
    catch(std::exception e)
    {
        std::cout << "STD Exception: " << e.what() << std::endl;
    }

    return 0;
}
