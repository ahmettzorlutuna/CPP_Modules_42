/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:32:31 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/13 14:32:31 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/Character.hpp"
#include "../includes/AMateria.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"

#include <iostream>

int main() {
    std::cout << "--- 1. PDF TEST ---" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << "\n--- 2. INVENTORY OVERFLOW TEST (NO LEAK) ---" << std::endl;
    // Toplamda 6 materyal oluşturuyoruz. 4'ü cebe, 2'si yere gidecek.
    for (int i = 0; i < 4; i++) {
        tmp = src->createMateria("ice");
        me->equip(tmp); // Envanter dolunca otomatik _floor'a gidecek.
    }

    std::cout << "\n--- 3. DEEP COPY & ASSIGNMENT TEST ---" << std::endl;
    Character* original = new Character("Original");
    original->equip(src->createMateria("ice"));
    
    Character* clone = new Character("Clone");
    *clone = *original; // Deep copy
    
    delete original; // Orijinal silindiğinde clone sapasağlam kalmalı.
    clone->use(0, *me);

    std::cout << "\n--- 4. UNEQUIP TEST ---" << std::endl;
    me->unequip(0); // Bu da _floor'a gidecek.

    std::cout << "\n--- CLEANING UP ---" << std::endl;
    delete me;
    delete clone;
    delete src;
    // Valgrind burada "0 leaks" demeli!
    return 0;
}