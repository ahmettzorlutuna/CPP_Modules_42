/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:45:43 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/20 23:45:44 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"
#include "../includes/Validator.hpp"

int main(int argc, char **argv)
{
    PhoneBook phonebook;
    std::string command;
    
    (void) argv;
    if(argc != 1)
        std::cout << "This program does not accept any arguments." << std::endl;
    while (true)
    {
        if(std::cin.eof())
        {
            std::cout << "\nEnd of input detected. Exiting program." << std::endl;
            break;
        }
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        
        if (!std::getline(std::cin, command))
        {
            std::cout << "\nEnd of input detected. Exiting program." << std::endl;
            break;
        }
        if (command == "ADD")
            phonebook.add_contact();
        else if (command == "SEARCH")
            phonebook.search_contact();
        else if(is_digit_only(command))
            phonebook.search_detail(command);
        else if (command == "EXIT")
        {
            std::cout << "Exiting program." << std::endl;
            break;
        }
        else
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
    }
    return 0;
}
