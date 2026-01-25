/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:29:42 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/22 00:29:43 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon)
    : _name(name), _weapon(weapon)
{}

void HumanA::attack() const {
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}