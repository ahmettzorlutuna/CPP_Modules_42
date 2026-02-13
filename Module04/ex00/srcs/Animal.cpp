/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:20:42 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/11 14:20:42 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "Animal makes a sound" << std::endl;
}

std::string Animal::getType() const
{
    return this->_type;
}