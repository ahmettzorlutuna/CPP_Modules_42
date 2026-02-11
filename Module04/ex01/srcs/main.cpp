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
    std::cout << "--- 1. PDF MANDATORY ARRAY TEST ---" << std::endl;

    const int numAnimals = 6;
    Animal* animals[numAnimals];

    for (int i = 0; i < numAnimals; i++) {
        if (i < numAnimals / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- 2. VIRTUAL DESTRUCTOR CHECK ---" << std::endl;

    for (int i = 0; i < numAnimals; i++) {
        delete animals[i];
    }

    std::cout << "\n--- 3. DEEP COPY TEST (DOG) ---" << std::endl;

    Dog basic;
    {

        Dog tmp = basic;
        std::cout << "Tmp dog created and will be destroyed soon." << std::endl;
    }
    std::cout << "Basic dog is still alive here." << std::endl;

    std::cout << "\n--- 4. ASSIGNMENT OPERATOR TEST (CAT) ---" << std::endl;

    Cat cat1;
    Cat cat2;
    cat2 = cat1;

    std::cout << "\n--- 5. TESTING INDEPENDENCE OF BRAINS ---" << std::endl;

    cat1.getBrain()->setIdea(0, "I want to eat fish.");
    std::cout << "Cat1's idea: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2's idea: " << cat2.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n--- END OF TESTS ---" << std::endl;
    return 0;
}