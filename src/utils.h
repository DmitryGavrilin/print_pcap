#pragma once

#include <string>
#include <stdlib.h>
#include <sstream>

namespace patch
{
    std::string to_string(int number)
    {
        std::ostringstream str;
        str << number;
        return str.str();
    }
}
