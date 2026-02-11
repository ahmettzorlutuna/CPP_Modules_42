/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:20:55 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/11 14:20:55 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->_type = "Dog";
}
Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        this->_type = other._type;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}