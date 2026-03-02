/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:58:54 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/24 15:58:55 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

#include <cctype>
#include <cfloat>
#include <iomanip>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

bool ScalarConverter::checkSpecialCases(const std::string& literal)
{
    if(literal == "nan" || literal == "nanf" ||
       literal == "+inf" || literal == "+inff" ||
       literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if(literal == "nan" || literal == "nanf")
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if(literal == "+inf" || literal == "+inff")
        {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else
        {   
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        return true;
    }
    return false;
}

bool ScalarConverter::isChar(const std::string& literal)
{
    return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool ScalarConverter::isInt(const std::string& literal)
{
    size_t i;

    i = 0;
    if(literal[i] == '-' || literal[i] == '+')
        i++;
    for(; i < literal.length(); i++)
    {
        if(!std::isdigit(literal[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::hasValidDecimalFormat(const std::string& literal, size_t start, bool hasF)
{
    bool hasDecimalPoint = false;
    size_t length = literal.length();

    if(hasF && literal[literal.length() - 1] == 'f')
        length--;
    for(size_t i = start; i < length; i++)
    {
        if(literal[i] == '.')
        {
            if(hasDecimalPoint)
                return false;
            hasDecimalPoint = true;
        }
        else if(!std::isdigit(literal[i]))
            return false;
    }
    return hasDecimalPoint;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
    if(literal[literal.length() - 1] != 'f')
        return false;
    size_t start = 0;
    if(literal[start] == '-' || literal[start] == '+')
        start++;
    return hasValidDecimalFormat(literal, start, true);
}

bool ScalarConverter::isDouble(const std::string& literal)
{
    if(literal[literal.length() - 1] == 'f')
        return false;
    size_t start = 0;
    if(literal[start] == '-' || literal[start] == '+')
        start++;
    return hasValidDecimalFormat(literal, start, false);
}

void ScalarConverter::printChar(double value)
{
    std::cout << "char: ";
    if(std::isnan(value) || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if(std::isprint(static_cast<char>(value)))
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printInt(double value)
{
    std::cout << "int: ";
    if(std::isnan(value) || value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
        std::cout << "impossible" << std::endl;
    else if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
    {
        std::cout << "impossible" << std::endl;
    }
    else
    {
        std::cout << static_cast<int>(value) << std::endl;
    }
    
}

void ScalarConverter::printFloat(double value)
{
    std::cout << "float: ";
    if(std::isnan(value) || value < -FLT_MAX || value > FLT_MAX)
        std::cout << "impossible" << std::endl;
    else
    {
        std::cout << std::fixed << std::setprecision(1) 
                << static_cast<float>(value) << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value)
{
    std::cout << "double: ";
    if(std::isnan(value) || value < -DBL_MAX || value > DBL_MAX)
        std::cout << "impossible" << std::endl;
    else
    {
        std::cout << std::fixed << std::setprecision(1) 
                << static_cast<double>(value) << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal)
{
    if (checkSpecialCases(literal)) return;

    char *endPtr;

    if (isChar(literal)) {
        double d = static_cast<double>(literal[0]);
        printChar(d);
        printInt(d);
        printFloat(d);
        printDouble(d);
        return;
    }

    double doubleValue = std::strtod(literal.c_str(), &endPtr);

    if (*endPtr != '\0') {
        if (!(*endPtr == 'f' && *(endPtr + 1) == '\0')) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }
    printChar(doubleValue);
    printInt(doubleValue);
    printFloat(doubleValue);
    printDouble(doubleValue);
}