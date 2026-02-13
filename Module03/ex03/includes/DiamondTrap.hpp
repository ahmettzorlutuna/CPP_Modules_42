/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:51:20 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/29 22:51:21 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "../includes/FragTrap.hpp"
#include "../includes/ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap();
        ~DiamondTrap();
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& other);
        DiamondTrap(std::string name);
        void    attack(const std::string& target);
        void    whoAmI();
    private:
        std::string _name;
};

#endif
