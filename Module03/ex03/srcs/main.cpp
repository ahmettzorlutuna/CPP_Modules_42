/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:50:56 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/29 22:50:57 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"
#include "../includes/FragTrap.hpp"
#include <iostream>

// Renkler (Hataları kaçırmamak için)
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

int main()
{
    std::cout << BLUE << "=== 1. CONSTRUCTION & DESTRUCTION CHAIN TEST ===" << RESET << std::endl;
    {
        // Beklenti:
        // 1. ClapTrap Constructor
        // 2. ScavTrap Constructor
        // 3. FragTrap Constructor
        // 4. DiamondTrap Constructor
        std::cout << GREEN << "[Creating DiamondTrap named 'Monster']" << RESET << std::endl;
        DiamondTrap d("Monster");

        std::cout << GREEN << "[Testing whoAmI]" << RESET << std::endl;
        d.whoAmI(); 
        // Çıktı: "I am DiamondTrap name: Monster" ve "I am ClapTrap name: Monster_clap_name" olmalı.

        std::cout << RED << "[Destructing 'Monster']" << RESET << std::endl;
        // Beklenti: Oluşum sırasının tam tersi. ClapTrap SADECE 1 KERE yok edilmeli!
    }
    std::cout << std::endl;

    std::cout << BLUE << "=== 2. ATTRIBUTE VALUES CHECK (CRITICAL) ===" << RESET << std::endl;
    {
        // Bu test, değerlerin doğru ebeveynden gelip gelmediğini kontrol eder.
        DiamondTrap d("Checker");
        
        // Bu değerlere erişmek için getter yazmadıysan, public değilse 
        // attack ve takeDamage fonksiyonlarının çıktılarına bakarak teyit etmelisin.
        // Veya geçici olarak değişkenleri public yapıp bakabilirsin (önerilmez ama debug için olur).
        
        std::cout << YELLOW << "--- Checking Stats via Actions ---" << RESET << std::endl;
        
        // 1. ATTACK (ScavTrap'ten gelmeli)
        // Mesaj "ScavTrap Checker attacks..." olmalı.
        d.attack("Dummy"); 
        
        // 2. DAMAGE (FragTrap'ten gelmeli: 30)
        // Attack mesajının sonunda "causing 30 points of damage" yazmalı.
        // Eğer 20 yazıyorsa ScavTrap'ten almışsın demektir -> HATA!
        
        // 3. ENERGY (ScavTrap'ten gelmeli: 50)
        // Bunu test etmek için 50 kere saldırı yaptırabilirsin (Amelik) 
        // ya da guardGate() çağırabiliyor mu diye bakabilirsin.
        d.guardGate();      // ScavTrap özelliği
        d.highFivesGuys();  // FragTrap özelliği
    }
    std::cout << std::endl;

    std::cout << BLUE << "=== 3. OCF / COPY / ASSIGNMENT TEST ===" << RESET << std::endl;
    {
        std::cout << GREEN << "[Creating Original]" << RESET << std::endl;
        DiamondTrap original("Original");
        
        std::cout << YELLOW << "--- Copy Constructor ---" << RESET << std::endl;
        DiamondTrap copy(original);
        copy.whoAmI(); // "Original" yazmalı

        std::cout << YELLOW << "--- Assignment Operator ---" << RESET << std::endl;
        DiamondTrap assigned("Temp");
        assigned = original;
        assigned.whoAmI(); // "Original" yazmalı
        
        std::cout << RED << "[Destructing Clones]" << RESET << std::endl;
    }

    std::cout << std::endl << BLUE << "=== END OF TESTS ===" << RESET << std::endl;
    return 0;
}