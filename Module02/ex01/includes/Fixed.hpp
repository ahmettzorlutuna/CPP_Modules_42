/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 22:37:31 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/23 22:37:31 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(const int intNum);
        Fixed(const float floatNum);
        Fixed(const Fixed &fixedNum);
        ~Fixed();
        Fixed &operator=(const Fixed &fixedNum);
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixedNum);
#endif