/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 21:05:52 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/24 21:05:52 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0)
{
}

Fixed::Fixed(const Fixed& other)
{
    this->_fixedPointValue = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed& other)
{
    if(this!=&other)
        this->_fixedPointValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int intValue)
{
    this->_fixedPointValue = intValue << this->_fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    this->_fixedPointValue = roundf(floatValue * (1 << this->_fractionalBits));
}

float Fixed::toFloat(void) const
{
    return (float)(this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->_fixedPointValue >> this->_fractionalBits);
}

int Fixed::getRawBits(void) const
{
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const value)
{
    this->_fixedPointValue = value;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;

    result.setRawBits(this->getRawBits() + other.getRawBits());

    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;

    result.setRawBits(this->getRawBits() - other.getRawBits());

    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    long long temp;

    temp = (long long)this->getRawBits() * (long long)other.getRawBits();

    temp = temp >> this->_fractionalBits;

    result.setRawBits((int)temp);

    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    long long temp;
    long long otherGetRaw;

    otherGetRaw = other.getRawBits();

    if(otherGetRaw == 0)
    {
        std::cerr << "Error: Division by zero!" << std::endl;
        return result;
    }

    temp = ((long long)this->getRawBits() * (1 << this->_fractionalBits)) / otherGetRaw;

    result.setRawBits((int)temp);

    return result;
}

bool Fixed::operator>(const Fixed& other) const
{
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->getRawBits() != other.getRawBits();
}

Fixed& Fixed::operator++(void)
{
    this->_fixedPointValue++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp;

    temp = *this;
    this->_fixedPointValue++;
    return (temp);
}

Fixed& Fixed::operator--(void)
{
    this->_fixedPointValue--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp;

    temp = *this;
    this->_fixedPointValue--;
    return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if(a < b)
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if(a < b)
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if(a > b)
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if(a > b)
        return (a);
    return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixedNum)
{
    out << fixedNum.toFloat();
    return (out);
}