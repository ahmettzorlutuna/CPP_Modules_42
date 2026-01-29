/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:50:54 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/29 22:50:54 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_Diamond_clap_name"), _name("Default_Diamond")
{
    this->FragTrap::_hitPoints = 100;
    this->ScavTrap::_energyPoints = 50;
    this->FragTrap::_attackDamage = 30;
    std::cout << "DiamondTrap " << this->_name << " constructed with default values." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->_name << " destructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    this->_name = other._name;
    std::cout << "DiamondTrap " << this->_name << " copy constructed." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->_name = other._name;
    }
    std::cout << "DiamondTrap " << this->_name << " assigned from another DiamondTrap." << std::endl;
    return *this;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    this->_name = name;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << this->_name << " constructed." << std::endl;
}

void    DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->_name << ", ClapTrap name: " << this->ClapTrap::_name << std::endl;
}