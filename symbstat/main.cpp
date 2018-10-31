#include <iostream>
#include <cstdint>
#include <unordered_map>
#include <string>
#include <fstream>

int main(int argc, char *argv[])
{
    std::string filePath;
    if(argc == 2)
    {
        filePath = argv[1];
        std::ifstream file(filePath);
        if(file)
        {
            char currentSymbol;
            std::unordered_map<char, uint64_t> symbolMatchCounter;
            while(file >> currentSymbol)
            {
                auto it = symbolMatchCounter.find(currentSymbol);
                if(it != symbolMatchCounter.end())
                {
                    ((*it).second)++;
                }
                else
                {
                    symbolMatchCounter.insert({currentSymbol, 1});
                }
            }

            for(auto symbStat : symbolMatchCounter)
            {
                std::cout << " Sym: " << symbStat.first << "\t\t " << symbStat.second << std::endl;
            }
        }
        else
        {
            std::cout << "Error! File can not be opened!" << std::endl;
        }
    }
    else
    {
        std::cout << "Error! Wrong using format." << std::endl;
        std::cout << "Usage: symbstat FILE_PATH" << std::endl;
    }

    return 0;
}
