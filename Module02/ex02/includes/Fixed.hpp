/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 21:06:05 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/24 21:06:06 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        Fixed(const int intValue);
        Fixed(const float floatValue);
        float toFloat(void) const;
        int toInt(void) const;
        int     getRawBits() const;
        void    setRawBits(int const raw);
        Fixed   operator+(const Fixed& other) const;
        Fixed   operator-(const Fixed& other) const;
        Fixed   operator*(const Fixed& other) const;
        Fixed   operator/(const Fixed& other) const;
        bool    operator>(const Fixed& other) const;
        bool    operator<(const Fixed& other) const;
        bool    operator>=(const Fixed& other) const;
        bool    operator<=(const Fixed& other) const;
        bool    operator==(const Fixed& other) const;
        bool    operator!=(const Fixed& other) const;
        Fixed&  operator++();
        Fixed   operator++(int);
        Fixed&  operator--();
        Fixed   operator--(int);
        static Fixed&    min(Fixed& a, Fixed& b);
        static const Fixed&  min(const Fixed& a, const Fixed& b);
        static Fixed&    max(Fixed& a, Fixed& b);
        static const Fixed&  max(const Fixed& a, const Fixed& b);
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixedNum);

#endif