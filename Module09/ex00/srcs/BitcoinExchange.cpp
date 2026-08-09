/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:44:56 by azorlutu          #+#    #+#             */
/*   Updated: 2026/05/26 15:44:57 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");

    if (!file.is_open())
    {
        throw std::runtime_error("Error: Could not open data.csv");
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t commaPosition = line.find(',');
        if (commaPosition != std::string::npos)
        {
            std::string date = line.substr(0, commaPosition);
            std::string value = line.substr(commaPosition + 1);
            try
            {
                std::istringstream ss(value);
                float rate;
                if (!(ss >> rate))
                {
                    throw std::invalid_argument("Error: Invalid value in data.csv");
                }
                
                _bitcoinData[date] = rate;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
    }
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _bitcoinData(other._bitcoinData)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->_bitcoinData = other._bitcoinData;
    }
    return *this;
}

void BitcoinExchange::parseFile(const std::string &filename) const
{
    if(_bitcoinData.empty())
    {
        std::cerr << "Error: Bitcoin data is empty." << std::endl;
        return;
    }

    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        try
        {
            size_t pipePosition = line.find('|');
            if (pipePosition == std::string::npos)
            {
                throw std::invalid_argument("Error: bad input => " + line);
            }

            std::string date = line.substr(0, pipePosition - 1);
            
            if (line.length() < pipePosition + 2)
            {
                throw std::invalid_argument("Error: bad input => " + line);
            }

            std::string valueStr = line.substr(pipePosition + 2);

            isValidDate(date);

            std::istringstream ss(valueStr);
            float value;
            if (!(ss >> value))
            {
                throw std::invalid_argument("Error: not valid number.");
            }

            isValidValue(value);

            float bitcoinValue = getBitcoinValue(date);

            std::cout << date << " => " << value << " = " << (value * bitcoinValue) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

float BitcoinExchange::getBitcoinValue(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = _bitcoinData.lower_bound(date);

    if (it != _bitcoinData.end() && it->first == date)
    {
        return it->second;
    }

    if (it == _bitcoinData.begin())
    {
        throw std::invalid_argument("Error: No older date available for " + date);
    }

    --it;
    return it->second;
}

void BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10)
    {
        throw std::invalid_argument("Error: bad input => " + date);
    }

    std::istringstream ss(date);
    int year, month, day;
    char char1, char2;

    if(!(ss >> year >> char1 >> month >> char2 >> day) || char1 != '-' || char2 != '-')
    {
        throw std::invalid_argument("Error: bad input => " + date);
    }

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        throw std::invalid_argument("Error: bad input => " + date);
    }

    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        daysInMonth[2] = 29;
    }

    if (day > daysInMonth[month])
    {
        throw std::invalid_argument("Error: bad input => " + date);
    }
}

void BitcoinExchange::isValidValue(float value) const
{
    if (value < 0)
    {
        throw std::invalid_argument("Error: not a positive number.");
    }
    if (value > 1000)
    {
        throw std::invalid_argument("Error: too large a number.");
    }
}
