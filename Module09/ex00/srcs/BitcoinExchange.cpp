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
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open data.csv" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
        size_t commaPosition = line.find(',');
        if (commaPosition != std::string::npos)
        {
            std::string date = line.substr(0, commaPosition);
            std::string value = line.substr(commaPosition + 1);
            try
            {
                float rate = std::atof(value.c_str());
                _bitcoinData[date] = rate;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error: Invalid value in data.csv" << std::endl;
            }
        }
    }
    file.close();
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
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
            std::string valueStr = line.substr(pipePosition + 2);

            isValidDate(date);

            float value = std::atof(valueStr.c_str());

            isValidValue(value);

            float bitcoinValue = getBitcoinValue(date);

            std::cout << date << " => " << value << " = " << (value * bitcoinValue) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    file.close();
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
        std::cerr << "Error: No older date available for " << date << std::endl;
        return 0.0f;
    }

    --it;
    return it->second;
}

void BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        throw std::invalid_argument("Error: bad input => " + date);
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        throw std::invalid_argument("Error: bad input => " + date);
    }
}

void BitcoinExchange::isValidValue(float value) const
{
    if (value < 0)
    {
        throw std::invalid_argument("Error: not a positive number");
    }
    if (value > 1000)
    {
        throw std::invalid_argument("Error: too large a number");
    }
}
