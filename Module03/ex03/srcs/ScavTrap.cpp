/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:19:09 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/29 22:51:07 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_name = "Default_ScavTrap";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " constructed with default values." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << " destructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << this->_name << " copy constructed." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap " << this->_name << " assigned from another ScavTrap." << std::endl;
    return *this;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " constructed." << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if(this->_energyPoints > 0 && this->_hitPoints > 0){
        this->_energyPoints--;
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    }
    else{
        std::cout << "ScavTrap " << this->_name << " has no energy or hit points left to attack." << std::endl;
    }
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode." << std::endl;
}
