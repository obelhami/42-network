#include "ScalarConverter.hpp"

static bool isChar(std::string& type)
{
    return type.length() == 1 && !isdigit(type[0]);
}

static bool isInt(const std::string& type) {
    char* end;
    long val = std::strtol(type.c_str(), &end, 10);
    (void)val;
    return *end == '\0';
}

static bool isFloat(const std::string& literal) {
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return true;
    char* end;
    std::strtof(literal.c_str(), &end);
    return (*end == 'f' && *(end+1) == '\0');
}

static bool isDouble(const std::string& literal) {
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return true;
    char* end;
    std::strtod(literal.c_str(), &end);
    return *end == '\0';
}
void ScalarConverter::convert(std::string literal)
{
    double value;

    if (isChar(literal)) {
        char c = literal[0];
        value = static_cast<double>(c);
    }
    else if (isInt(literal)) {
        value = std::strtol(literal.c_str(), NULL, 10);
    }
    else if (isFloat(literal)) {
        value = std::strtof(literal.c_str(), NULL);
    }
    else if (isDouble(literal)) {
        value = std::strtod(literal.c_str(), NULL);
    }
    else {
        std::cerr << "Error: invalid literal" << std::endl;
        return;
    }

    // Print char
    std::cout << "char: ";
    if (std::isnan(value) || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (std::isprint(static_cast<char>(value)))
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    // Print int
    std::cout << "int: ";
    if (std::isnan(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;

    // Print float
    if ((value == HUGE_VAL || value == -HUGE_VAL || value == 0.0) && (errno == ERANGE)) {
        std::cout << "float: impossible\n";
    }else{
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    }
        // Print double
    if ((value == HUGE_VAL || value == -HUGE_VAL || value == 0.0) && (errno == ERANGE)) {
        std::cout << "double: impossible\n";
    }else{
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}}