/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:29:31 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/22 00:29:32 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string name)
    : _name(name), _weapon(nullptr)
{}

// HumanB::HumanB(std::string name)
// {
//     this->_name = name;
//     this->_weapon = NULL;
// }

void HumanB::setWeapon(Weapon& weapon) {
    this->_weapon = &weapon;
}

void HumanB::attack() const {
    if (this->_weapon)
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " has no weapon to attack with!" << std::endl;
}