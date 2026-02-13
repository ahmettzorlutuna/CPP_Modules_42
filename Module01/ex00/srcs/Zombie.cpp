/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:38:17 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/21 20:38:18 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(std::string name)
{
    this->_name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->_name << " is destroyed." << std::endl;
}

void Zombie::announce(void) const
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
