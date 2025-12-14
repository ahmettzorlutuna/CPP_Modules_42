#ifndef VALIDATORS_HPP
#define VALIDATORS_HPP

#include <string>

bool is_alpha_only(const std::string& str);
bool is_digit_only(const std::string& str);
bool is_nickname_valid(const std::string& str);
bool is_secret_valid(const std::string& str);
std::string ask_until_valid(const std::string& prompt, bool (*validator)(const std::string&), const std::string& error_msg);

#endif