/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:21:00 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/11 14:21:00 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

#include <iostream>

int main() {
    std::cout << "--- 1. ABSTRACT CLASS INSTANTIATION TEST ---" << std::endl;

    AAnimal test;

    std::cout << "Cannot instantiate Animal directly. Check!" << std::endl;

    std::cout << "\n--- 2. POLYMORPHISM TEST (AS BEFORE) ---" << std::endl;

    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << "Dog type: " << j->getType() << " " << std::endl;
    std::cout << "Cat type: " << i->getType() << " " << std::endl;

    j->makeSound();
    i->makeSound();

    std::cout << "\n--- 3. CLEANING UP ---" << std::endl;

    delete j;
    delete i;

    std::cout << "\n--- 4. DEEP COPY STILL WORKS? ---" << std::endl;

    Dog basic;
    {
        Dog tmp = basic;
        std::cout << "Tmp dog created as a copy." << std::endl;
    }
    std::cout << "Basic dog is fine after deep copy test." << std::endl;

    return 0;
}