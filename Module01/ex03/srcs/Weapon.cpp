/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:29:12 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/22 00:29:12 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type){
    this->_type = type;
}

const std::string& Weapon::getType() const {
    return this->_type;
}

void Weapon::setType(const std::string& type){
    this->_type = type;
}