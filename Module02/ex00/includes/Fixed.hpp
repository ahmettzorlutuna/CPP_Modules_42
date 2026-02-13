/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 21:41:52 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/23 21:41:53 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;
};

#endif