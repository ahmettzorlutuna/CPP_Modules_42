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
    std::cout << "--- 1. PDF MANDATORY TEST ---" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "\n--- 2. DEEP COPY TEST (CHARACTER) ---" << std::endl;
    // Bir karakter yarat ve envanterini doldur
    Character* original = new Character("Original");
    original->equip(src->createMateria("ice"));
    
    // Copy Constructor: Orijinalin kopyasını oluştur
    Character* copy = new Character(*original);
    
    std::cout << "Original name: " << original->getName() << std::endl;
    std::cout << "Copy name: " << copy->getName() << std::endl;
    
    // Orijinali siliyoruz. Eğer sığ kopyalama yaptıysan copy patlar!
    delete original;
    std::cout << "Original deleted. Testing copy's materia:" << std::endl;
    copy->use(0, *bob);

    std::cout << "\n--- 3. FULL INVENTORY & FLOOR PROTECTION ---" << std::endl;
    // Envanterde 4 slot var. Fazlasını ekleyelim.
    for (int i = 0; i < 6; i++) {
        tmp = src->createMateria("ice");
        me->equip(tmp); // Envanter dolunca senin mantığınla _floor'a gitmeli.
    }

    std::cout << "\n--- 4. UNEQUIP & LEAK TEST ---" << std::endl;
    // Bir eşyayı yere atalım. PDF'e göre silinmemeli ama sızmamalı!
    me->unequip(1); 
    std::cout << "Materia at slot 1 unequipped to floor." << std::endl;

    std::cout << "\n--- 5. UNKNOWN MATERIA TEST ---" << std::endl;
    tmp = src->createMateria("fire"); // Bilinmeyen tip NULL dönmeli
    if (tmp == NULL)
        std::cout << "Unknown materia type returned NULL as expected." << std::endl;

    std::cout << "\n--- CLEANING UP ---" << std::endl;
    delete bob;
    delete me;
    delete copy;
    delete src;

    return 0;
}