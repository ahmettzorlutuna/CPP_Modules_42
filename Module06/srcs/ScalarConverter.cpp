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


void ScalarConverter::convert(const std::string& literal)
{
    if(checkSpecialCases(literal))
        return;
    if(isChar(literal))
        std::cout << "Literal is a char." << std::endl;
    else if(isInt(literal))
        std::cout << "Literal is an int." << std::endl;
    else if(isFloat(literal))
        std::cout << "Literal is a float." << std::endl;
    else if(isDouble(literal))
        std::cout << "Literal is a double." << std::endl;
    else
        std::cout << "Unknown literal: " << literal << std::endl;
}