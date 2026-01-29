/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:33:48 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/29 19:33:49 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include <iostream>

// Renkli çıktılar (Gözün bayram etsin diye değil, hatayı gör diye)
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main()
{
    std::cout << BLUE << "=== 1. CONSTRUCTOR CHAINING TEST ===" << RESET << std::endl;
    {
        // Burada beklenti:
        // 1. ClapTrap Constructor çalışacak.
        // 2. ScavTrap Constructor çalışacak.
        // 3. Değerler (100 HP, 50 Energy, 20 Damage) set edilecek.
        
        std::cout << GREEN << "[Creating ScavTrap named 'Serena']" << RESET << std::endl;
        ScavTrap serena("Serena");
        
        std::cout << GREEN << "[Testing Attributes via Attack]" << RESET << std::endl;
        // ClapTrap 0 vururdu, ScavTrap 20 vurmalı. Çıktıya dikkat et!
        serena.attack("Target Dummy"); 
        
        std::cout << GREEN << "[Testing Special Ability]" << RESET << std::endl;
        serena.guardGate();
        
        // Scope bitiyor... Destructor sırası: ScavTrap -> ClapTrap olmalı.
        std::cout << RED << "[Destructing 'Serena']" << RESET << std::endl;
    }
    
    std::cout << std::endl << BLUE << "=== 2. OCF & COPY TEST ===" << RESET << std::endl;
    {
        ScavTrap a("Original");
        a.takeDamage(50); // HP: 100 -> 50
        
        std::cout << YELLOW << "--- Copying ScavTrap ---" << RESET << std::endl;
        ScavTrap b(a); // Copy Constructor
        
        // b'nin canı da 50 olmalı.
        std::cout << "Original HP was lowered to 50. Copy should be same." << std::endl;
        b.guardGate(); // Çalışıyor mu?
    }

    std::cout << std::endl << BLUE << "=== 3. CLAPTRAP VS SCAVTRAP TEST ===" << RESET << std::endl;
    {
        // Polimorfizm testi (Henüz virtual değil ama farkı görmek için)
        ClapTrap clap("Clappy");
        ScavTrap scav("Scavvy");

        std::cout << "--- FIGHT START ---" << std::endl;
        
        clap.attack("Scavvy"); // ClapTrap Attack (0 dmg)
        scav.takeDamage(0);
        
        scav.attack("Clappy"); // ScavTrap Attack (20 dmg)
        clap.takeDamage(20);   // ClapTrap (10 HP) mefta olmalı.
        
        // Ölen ClapTrap'i tamir etmeyi dene
        clap.beRepaired(10); 
    }

    std::cout << std::endl << BLUE << "=== END OF TESTS ===" << RESET << std::endl;
    return 0;
}