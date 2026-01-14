#include "Scalar.hpp"

ScalarConvert::ScalarConvert()
{
    std::cout << "Default ScalarConvert Constructor called" << std::endl;
}

ScalarConvert& ScalarConvert::operator=(const ScalarConvert& src)
{
    if (this != &src)
        (void)src;
    return (*this);
}

ScalarConvert::ScalarConvert(const ScalarConvert& copy)
{
    (void)copy;
}

ScalarConvert::~ScalarConvert()
{
    std::cout << "Default ScalarConvert Destructor called" << std::endl;
}

bool isChar(const std::string& literal)
{
    return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool isInt(const std::string& literal)
{
    size_t i = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    for (; i < literal.length(); i++)
    {
        if (!std::isdigit(literal[i]))
            return false;
    }
    return true;
}

bool isFloat(const std::string& literal)
{
    size_t i = 0;
    bool dotFound = false;

    if (literal.empty())
        return (false);
    if (literal[literal.length() - 1] != 'f')
        return (false);
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    for (; i < literal.length() - 1; i++)
    {
        if (literal[i] == '.')
        {
            if (dotFound)
                return (false);
            dotFound = true;
            continue;
        }
        if (!std::isdigit(literal[i]))
            return (false);
    }
    return (true);
}

bool isDouble(const std::string& literal)
{
    size_t i = 0;
    bool dotFound = false;

    if (literal.empty())
        return (false);
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    for (; i < literal.length(); i++)
    {
        if (literal[i] == '.')
        {
            if (dotFound)
                return (false);
            dotFound = true;
            continue;
        }
        if (!std::isdigit(literal[i]))
            return (false);
    }
    return (true);
}

bool isSpecialLiteral(const std::string& literal)
{
    return (literal == "nan" || literal == "+inf" || literal == "-inf" ||
            literal == "nanf" || literal == "+inff" || literal == "-inff");
}

void convertFromChar(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void    convertFromInt(long i)
{
    if (i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(i))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

    if (i < MIN_INT || i > MAX_INT)
        std::cout << "int: out of limits" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(i) << std::endl;

    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void    convertFromFloat(float f)
{
    if (f < 0 || f > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(f)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    
    if (f < MIN_INT || f > MAX_INT)
        std::cout << "int: out of limits" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;

    if (f < MIN_FLOAT || f > MAX_FLOAT)
        std::cout << "float: out of limits" << std::endl;
    else
        std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
}

void    convertFromDouble(double d)
{
    if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    
    if (d < MIN_INT || d > MAX_INT)
        std::cout << "int: out of limits" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    
    if (d < MIN_FLOAT || d > MAX_FLOAT)
        std::cout << "float: out of limits" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
    
    if (d < MIN_DOUBLE || d > MAX_DOUBLE)
        std::cout << "double: out of limits" << std::endl;
    else
        std::cout << "double: " << d << ".0" << std::endl;
}

void    convertFromSpecialLiteral(const std::string& literal)
{
    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "+inf" || literal == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void ScalarConvert::convert(std::string const & literal)
{
    if (isChar(literal))
        convertFromChar(literal[0]);
    else if (isInt(literal))
    {
        long val = std::strtol(literal.c_str(), NULL, 10);
        convertFromInt(val);
    }
    else if (isFloat(literal))
    {
        float f = std::strtof(literal.c_str(), NULL);
        convertFromFloat(f);
    }
    else if (isDouble(literal))
    {
        double d = std::strtod(literal.c_str(), NULL);
        convertFromDouble(d);
    }
    else if (isSpecialLiteral(literal))
        convertFromSpecialLiteral(literal);
    else
        std::cout << "Error: Invalid literal format." << std::endl;
}