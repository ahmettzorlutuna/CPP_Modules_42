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

AAnimal::AAnimal() : _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

void AAnimal::makeSound() const
{
    std::cout << "Animal makes a sound" << std::endl;
}

std::string AAnimal::getType() const
{
    return this->_type;
}