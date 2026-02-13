/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:18:53 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/29 22:50:27 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructed with default values." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    std::cout << "ClapTrap " << _name << " copy constructed." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap " << _name << " assigned from another ClapTrap." << std::endl;
    return *this;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructed." << std::endl;
}

void    ClapTrap::attack(const std::string& target){
    if(this->_energyPoints > 0 && this->_hitPoints > 0){
        this->_energyPoints--;
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    }
    else{
        std::cout << "ClapTrap " << this->_name << " has no energy or hit points left to attack." << std::endl;
    }
}

void   ClapTrap::takeDamage(unsigned int amount){
    if(this->_hitPoints <= amount){
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage and is now destroyed!" << std::endl;
    }
    else{
        this->_hitPoints -= amount;
        std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage, remaining hit points: " << this->_hitPoints << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount){
    if(this->_energyPoints > 0 && this->_hitPoints > 0){
        this->_energyPoints--;
        this->_hitPoints += amount;
        std::cout << "ClapTrap " << this->_name << " repaired itself for " << amount << " hit points, total hit points: " << this->_hitPoints << std::endl;
    }
    else{
        std::cout << "ClapTrap " << this->_name << " has no energy or hit points left to repair." << std::endl;
    }
}
