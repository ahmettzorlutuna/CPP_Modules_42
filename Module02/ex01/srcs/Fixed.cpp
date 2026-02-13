/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 22:37:10 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/23 22:37:10 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intNum)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = intNum << this->_fractionalBits;
}

Fixed::Fixed(const float floatNum)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(floatNum * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &fixedNum)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_fixedPointValue = fixedNum.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixedNum)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixedNum)
        this->_fixedPointValue = fixedNum.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const
{
    return this->_fixedPointValue;
}

void Fixed::setRawBits( int const value )
{
    this->_fixedPointValue = value;
}

float Fixed::toFloat( void ) const
{
    return (float)(this->_fixedPointValue) / (1 << this->_fractionalBits);
}

int Fixed::toInt( void ) const
{
    return this->_fixedPointValue >> this->_fractionalBits;
}

std::ostream &operator<<(std::ostream& out, const Fixed&fixedNum)
{
    out << fixedNum.toFloat();
    return out;
}