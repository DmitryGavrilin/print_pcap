#include "CParceArgs.h"
#include <stdlib.h>

CParceArgs::CParceArgs(int argc, char *argv[])
{
    std::vector<std::string> args;
    ipFilter_.clear();
    portFilter_=0;
    nameFile_.clear();

    for (int var = 1; var < argc; ++var)
        args.push_back(std::string(argv[var]));
    for(std::vector<std::string>::iterator it = args.begin(); it != args.end();)
    {
        if (*it == "-a")
        {
            ++it;
            ipFilter_ = *it;
            ++it;
            continue;
        }
        if (*it == "-p")
        {
            ++it;
            portFilter_ = atoi(std::string(*it).c_str());
            ++it;
            continue;
        }
        nameFile_ = *it;
        ++it;
        continue;
    }
}

std::string CParceArgs::getNameFile()
{
    return nameFile_;
}

int CParceArgs::getPortFilter()
{
    return portFilter_;
}

std::string CParceArgs::getIpFilter()
{
    return ipFilter_;
}
