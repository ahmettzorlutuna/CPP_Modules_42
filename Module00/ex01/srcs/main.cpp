#include <iostream>

#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

int main(int argc, char **argv)
{
    PhoneBook phonebook;
    std::string command;
    
    if(argc != 1 || argv[1] != NULL)
        std::cout << "This program does not accept any arguments." << std::endl;
    while (true)
    {
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