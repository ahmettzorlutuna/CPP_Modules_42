/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:42:00 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/23 19:42:01 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
    public:
        Harl();
        ~Harl();
        void    complain(std::string level);
    private:
        void    debug( void );
        void    info( void );
        void    warning( void );
        void    error( void );
};

#endif