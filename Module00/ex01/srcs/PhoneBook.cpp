/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:46:15 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/20 23:46:16 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include "../includes/Validator.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>

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
    if(std::cin.eof())  return;
    last_name = ask_until_valid("Enter last name: ", is_alpha_only, "Last name must contain only alphabetic characters. Please try again.");
    if(std::cin.eof())  return;
    nickname = ask_until_valid("Enter nickname: ", is_nickname_valid, "Nickname must be at least 2 characters long and contain only alphanumeric characters or underscores. Please try again.");
    if(std::cin.eof())  return;
    phone_number = ask_until_valid("Enter phone number: ", is_digit_only, "Phone number must contain only numeric characters. Please try again.");
    if(std::cin.eof())  return;
    darkest_secret = ask_until_valid("Enter darkest secret: ", is_secret_valid, "Darkest secret must contain at least one non-space character. Please try again.");
    if(std::cin.eof())  return;
    
    int index = this->_next_index;
    this->_contacts[index].setAllFields(first_name, last_name, nickname, phone_number, darkest_secret);
    this->_next_index = (this->_next_index + 1) % 8;
    if(this->_contact_count < 8)
        this->_contact_count++;
}

void PhoneBook::search_contact(void) const
{
    if (this->_contact_count == 0)
    {
        std::cout << "PhoneBook is empty. Please add contacts first." <<  std::endl;
        return;
    }
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    for (int i = 0; i < this->_contact_count; ++i)
    {
        std::cout << "|" << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncate_field(this->_contacts[i].get_first_name()) << "|";
        std::cout << std::setw(10) << truncate_field(this->_contacts[i].get_last_name()) << "|";
        std::cout << std::setw(10) << truncate_field(this->_contacts[i].get_nickname()) << "|" << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;
    return;
}

void PhoneBook::search_detail(const std::string& command) const
{
    if( this->_contact_count == 0)
    {
        std::cout << "PhoneBook is empty. Please add contacts first." <<  std::endl;
        return;
    }
    int index;
    std::stringstream ss(command);
    ss >> index;
    if (index < 0 || index >= this->_contact_count)
    {
        std::cout << "Index out of range. Please enter a valid index between 0 and " << this->_contact_count - 1 << "." << std::endl;
        return;
    }
    std::cout << "First Name: " << this->_contacts[index].get_first_name() << std::endl;
    std::cout << "Last Name: " << this->_contacts[index].get_last_name() << std::endl;
    std::cout << "Nickname: " << this->_contacts[index].get_nickname() << std::endl;
    std::cout << "Phone Number: " << this->_contacts[index].get_phone_number() << std::endl;
    std::cout << "Darkest Secret: " << this->_contacts[index].get_darkest_secret() << std::endl;
}
