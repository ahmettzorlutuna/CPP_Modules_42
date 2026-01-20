/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Validator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:46:21 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/20 23:46:21 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

bool is_alpha_only(const std::string& str)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        char c = str[i];
        if (!std::isalpha(c))
            return false;
    }
    return true;
}

bool is_digit_only(const std::string& str)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        char c = str[i];
        if (!std::isdigit(c))
            return false;
    }
    return true;
}

bool is_nickname_valid(const std::string& str)
{
    if (str.length() < 2)
        return false;
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isalnum(str[i]) && str[i] != '_')
            return false;
    }
    return true;
}

bool is_secret_valid(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isspace(str[i]))
            return true;
    }
    return false;
}

std::string truncate_field(const std::string& field)
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

std::string ask_until_valid(const std::string& prompt, bool (*validator)(const std::string&), const std::string& error_msg)
{
    std::string input;
    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
        {
            std::cout << "Input terminated (EOF detected)." << std::endl;
            return ("");
        }
        if(input.empty())
        {
            std::cout << "Input error or empty input. Please try again." << std::endl;
            continue;
        }
        if(!validator(input))
        {
            std::cout << error_msg << std::endl;
            continue;
        }
        return input;
    }
}
