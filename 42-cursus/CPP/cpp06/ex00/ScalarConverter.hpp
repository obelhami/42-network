#pragma once

#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cerrno>
#include <string>

class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        static void convert(std::string type);
};