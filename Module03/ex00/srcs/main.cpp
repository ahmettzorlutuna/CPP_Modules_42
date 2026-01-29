/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 21:08:49 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/25 21:08:52 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include <iostream>

// Renkli çıktılar (Hataları daha net görmek için)
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

int main()
{
    std::cout << BLUE << "=== 1. CONSTRUCTION & DESTRUCTION TEST ===" << RESET << std::endl;
    {
        // Yığın (Stack) üzerinde nesneler
        ClapTrap a("Alpha");
        ClapTrap b("Beta");
        
        // Copy Constructor Testi
        std::cout << YELLOW << "[TEST] Copy Constructor (ClapTrap c(a))" << RESET << std::endl;
        ClapTrap c(a);

        // Copy Assignment Operator Testi
        std::cout << YELLOW << "[TEST] Assignment Operator (c = b)" << RESET << std::endl;
        c = b; // c artık Beta'nın özelliklerini almalı
    }
    std::cout << std::endl;

    std::cout << BLUE << "=== 2. COMBAT & DAMAGE LOGIC TEST ===" << RESET << std::endl;
    {
        ClapTrap warrior("Warrior");

        // 1. Saldırı (Enerji harcamalı)
        warrior.attack("Target Dummy");
        
        // 2. Hasar Alma
        std::cout << YELLOW << "[TEST] Taking 5 damage" << RESET << std::endl;
        warrior.takeDamage(5); // HP: 10 -> 5

        // 3. Tamir Olma (Enerji harcamalı)
        std::cout << YELLOW << "[TEST] Repairing 3 HP" << RESET << std::endl;
        warrior.beRepaired(3); // HP: 5 -> 8

        // 4. FATAL DAMAGE (Overflow Kontrolü)
        std::cout << YELLOW << "[TEST] Taking MASSIVE damage (Overkill)" << RESET << std::endl;
        warrior.takeDamage(500); // HP: 8 -> 0 (Eğer unsigned underflow olursa 4 milyar olur!)
        
        // 5. Ölü Robot İşlem Yapamaz
        std::cout << YELLOW << "[TEST] Action while dead" << RESET << std::endl;
        warrior.attack("Ghost"); // "Canı yok, saldıramaz" demeli
        warrior.beRepaired(10);  // "Canı yok, tamir olamaz" demeli
    }
    std::cout << std::endl;

    std::cout << BLUE << "=== 3. ENERGY DEPLETION TEST ===" << RESET << std::endl;
    {
        ClapTrap worker("Worker");

        // Enerjiyi bitirene kadar saldırtıyoruz (Başlangıç 10 Enerji)
        for (int i = 0; i < 12; i++)
        {
            std::cout << "Action " << i + 1 << ": ";
            worker.attack("Wall");
        }
        // 10. saldırıdan sonra "Enerji yok" demeli.
    }
    
    std::cout << std::endl << BLUE << "=== END OF TESTS ===" << RESET << std::endl;
    return 0;
}

