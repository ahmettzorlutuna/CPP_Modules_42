/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:19:00 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/29 20:19:01 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"
#include "../includes/ScavTrap.hpp" // Kıyaslama yapmak istersen ekle, yoksa silebilirsin.
#include <iostream>

// Hataları ve önemli noktaları görmek için renkler
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"   

int main()
{
    std::cout << BLUE << "=== 1. CONSTRUCTION CHAIN TEST ===" << RESET << std::endl;
    {
        // Beklenti: Önce ClapTrap, Sonra FragTrap constructor mesajı.
        std::cout << GREEN << "[Creating FragTrap named 'Grenade']" << RESET << std::endl;
        FragTrap frag("Grenade");

        std::cout << GREEN << "[Check Stats]" << RESET << std::endl;
        // FragTrap stats: 100 HP, 100 Energy, 30 Damage
        // Attack fonksiyonunu ezmediğin için "ClapTrap ... attacks" yazabilir 
        // AMA hasar miktarı 30 OLMALI.
        frag.attack("Enemy Bunker"); 
        
        std::cout << GREEN << "[Check Special Ability]" << RESET << std::endl;
        frag.highFivesGuys();

        std::cout << RED << "[Destructing 'Grenade']" << RESET << std::endl;
        // Beklenti: Önce FragTrap, Sonra ClapTrap destructor mesajı.
    }
    std::cout << std::endl;

    std::cout << BLUE << "=== 2. OCF & DEEP COPY TEST ===" << RESET << std::endl;
    {
        std::cout << GREEN << "[Creating Original]" << RESET << std::endl;
        FragTrap original("Original");
        original.takeDamage(20); // HP 100 -> 80

        std::cout << YELLOW << "--- Copying (Copy Constructor) ---" << RESET << std::endl;
        FragTrap copy(original);
        // Copy'nin HP'si de 80 olmalı.
        // Copy'nin ismi de "Original" olmalı.
        copy.highFivesGuys();

        std::cout << YELLOW << "--- Assigning (Operator=) ---" << RESET << std::endl;
        FragTrap assigned("Temp");
        assigned = original;
        // Assigned da artık Original'ın özelliklerine sahip olmalı.
        
        std::cout << RED << "[Destructing All 3 Objects]" << RESET << std::endl;
    }
    std::cout << std::endl;

    std::cout << BLUE << "=== 3. CLAP vs SCAV vs FRAG (Damage Comparison) ===" << RESET << std::endl;
    {
        // Mirasın gücünü görmek için.
        ClapTrap clap("Clappy"); // 0 Damage
        // ScavTrap scav("Scavvy"); // 20 Damage (Dosyan varsa açabilirsin)
        FragTrap frag("Fraggy"); // 30 Damage

        std::cout << "--- ATTACK LOGS ---" << std::endl;
        clap.attack("Target"); // Hasar: 0
        // scav.attack("Target"); // Hasar: 20
        frag.attack("Target"); // Hasar: 30 (EN GÜÇLÜSÜ)
    }

    std::cout << std::endl << BLUE << "=== END OF TESTS ===" << RESET << std::endl;
    return 0;
}