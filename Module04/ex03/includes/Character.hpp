/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:48:04 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/12 17:48:05 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
    public:
        Character();
        ~Character();
        Character(Character const &other);
        Character& operator=(Character const &other);
    
    
        Character(std::string const &name);
        std::string const &getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
    private:
        std::string _name;
        AMateria* _inventory[4];
        AMateria* _floor[100];
        int _floorCount;
};

#endif