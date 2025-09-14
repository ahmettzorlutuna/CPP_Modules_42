#include "../includes/PhoneBook.hpp"
#include "../includes/Validator.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
    std::cout << "Welcome to your PhoneBook!" << std::endl;
    this->_contact_count = 0;
    this->_next_index = 0;
}

void PhoneBook::add_contact(void)
{
    std::string first_name, last_name, nickname, phone_number, darkest_secret;
    
    first_name = ask_until_valid("Enter first name: ", is_alpha_only, "First name must contain only alphabetic characters. Please try again.");
    last_name = ask_until_valid("Enter last name: ", is_alpha_only, "Last name must contain only alphabetic characters. Please try again.");
    nickname = ask_until_valid("Enter nickname: ", is_nickname_valid, "Nickname must be at least 2 characters long and contain only alphanumeric characters or underscores. Please try again.");
    phone_number = ask_until_valid("Enter phone number: ", is_digit_only, "Phone number must contain only numeric characters. Please try again.");
    darkest_secret = ask_until_valid("Enter darkest secret: ", is_secret_valid, "Darkest secret must contain at least one non-space character. Please try again.");
    
    int index = this->_next_index;
    this->_contacts[index].setAllFields(first_name, last_name, nickname, phone_number, darkest_secret);
    this->_next_index = (this->_next_index + 1) % 8;
    if(this->_contact_count < 8)
        this->_contact_count++;
}

void PhoneBook::search_contact(void) const
{
    return;
}