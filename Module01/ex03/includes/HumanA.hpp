/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:30:12 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/22 00:30:13 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
    public:
        HumanA(std::string name, Weapon& weapon);
        void attack() const;
    private:
        std::string _name;
        Weapon& _weapon;
};

#endif