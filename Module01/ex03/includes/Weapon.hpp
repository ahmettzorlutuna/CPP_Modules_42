/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:29:57 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/22 00:29:58 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
class Weapon {
    public:
        Weapon(std::string type);
        const std::string& getType() const;
        void setType(const std::string& type);
    private:
        std::string _type;
};

#endif

