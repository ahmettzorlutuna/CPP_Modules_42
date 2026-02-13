/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:19:16 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/29 20:19:16 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    public:
        ClapTrap();
        ~ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ClapTrap(std::string name);
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
    protected:
        std::string     _name;
        unsigned int    _hitPoints;
        unsigned int    _energyPoints;
        unsigned int    _attackDamage;
};
#endif