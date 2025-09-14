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

std::string ask_until_valid(const std::string& prompt, bool (*validator)(const std::string&), const std::string& error_msg)
{
    std::string input;
    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input) || input.empty())
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