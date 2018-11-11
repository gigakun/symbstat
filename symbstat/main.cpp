#include <iostream>
#include <cstdint>
#include <map>
#include <string>
#include <fstream>
#include <memory>

#include <unordered_map>
#include <set>

#include "filewrapper.h"
#include "argsparser.h"

struct valueCmp {
    bool operator()(std::pair<char, uint64_t> a, std::pair<char, uint64_t> b) {
        bool result = false;
        if(a.second == b.second)
        {
            result = a.first < b.first;
        }
        else
        {
            result = a.second < b.second;
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    try {
        std::unique_ptr<IAppConfig> config(new ArgsParser(argc, argv));

        FileWrapper file(config->GetFileName());
        char currentSymbol;
        std::unordered_map<char, uint64_t> symbolMatchCounter;
        while(file.GetChar(currentSymbol))
        {
            symbolMatchCounter[currentSymbol]++;
        }
        std::multiset<std::pair<char, uint64_t>, valueCmp> multisetSortedByValue(symbolMatchCounter.begin(), symbolMatchCounter.end());
        for(auto symbStat : multisetSortedByValue)
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
