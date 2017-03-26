#pragma once

#include <vector>
#include <string>

class CParceArgs
{
public:
    CParceArgs(int argc, char *argv[]);

    std::string getNameFile();
    int getPortFilter();
    std::string getIpFilter();
private:
    std::string nameFile_;
    int portFilter_;
    std::string ipFilter_;
};
