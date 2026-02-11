/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:21:29 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/11 14:21:29 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    this->_type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        WrongAnimal::operator=(other);
    }
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}