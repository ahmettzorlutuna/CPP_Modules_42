/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:30:04 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/22 00:30:05 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
    public:
        HumanB(std::string name);
        void setWeapon(Weapon& weapon);
        void attack() const;
    private:
        std::string _name;
        Weapon* _weapon;
};

#endif

