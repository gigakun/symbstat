#include <iostream>
#include <cstdint>
#include <map>
#include <string>
#include <fstream>

#include "filewrapper.h"

int main(int argc, char *argv[])
{
    bool continueFlag = false;
    std::string filePath;
    if(argc == 2)
    {
        filePath = argv[1];
        continueFlag = true;
    }
    else
    {
        std::cout << "Error! Wrong using format." << std::endl;
        std::cout << "Usage: symbstat FILE_PATH" << std::endl;
    }
    try {
        FileWrapper file(filePath);
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

    } catch (std::string e) {
        std::cout << "Exception: " << e << std::endl;
    }

    return 0;
}
