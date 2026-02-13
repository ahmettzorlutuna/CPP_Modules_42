/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:20:48 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/11 14:20:48 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->_brain;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*other._brain);
        this->_type = other._type;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}

Brain* Cat::getBrain() const
{
    return this->_brain;
}
