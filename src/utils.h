#pragma once

#include <string>
#include <stdlib.h>
#include <sstream>
#include <ctime>
#include <cstdio>

namespace patch
{
    std::string to_string(int number)
    {
        std::ostringstream str;
        str << number;
        return str.str();
    }

    template <typename T>
    void swapEnd(T& var)
    {
        char* varSwapped = new char[sizeof(var)];
        for(long i = 0; i < static_cast<long>(sizeof(var)); i++)
            varSwapped[sizeof(var) - 1 - i] = ((char*)(&var))[i];
        for(long i = 0; i < static_cast<long>(sizeof(var)); i++)
            ((char*)(&var))[i] = varSwapped[i];
        delete[] varSwapped;
    }

    std::string timestemp(const long &tv_sec, const long &tv_usec)
    {
        struct tm *nowtm = NULL;
        time_t nowtime = tv_sec;
        nowtm = gmtime(&nowtime);

        char tmbuf[64], buf[64];
        if (nowtm != NULL)
        {
            strftime(tmbuf, sizeof(tmbuf), "%Y-%m-%d %H:%M:%S", nowtm);
            snprintf(buf, sizeof(buf), "%s.%06lu", tmbuf, tv_usec);
        }
        else
            snprintf(buf, sizeof(buf), "0000-00-00 00:00:00.000000");

        return std::string(buf);
    }

}
