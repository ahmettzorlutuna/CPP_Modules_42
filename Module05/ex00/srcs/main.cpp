/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:02:58 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/17 13:02:58 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

void checkSegments() {
    const char* literal = "I am in Text Segment";
    std::string stackStr = "I am a managed heap data in Stack";
    
    std::cout << "Literal Adresi: " << (void*)literal << " (Very low address - Text)" << std::endl;
    std::cout << "Stack Degiskeni: " << &stackStr << " (Very high address - Stack)" << std::endl;

    std::cout << "Heap Verisi:    " << (void*)stackStr.c_str() << " (medium address - Heap)" << std::endl;
}

void testBureaucrat(std::string name, int grade) {
    std::cout << "--- Testing: " << name << " with grade " << grade << " ---" << std::endl;
    try {
        Bureaucrat b(name, grade);
        std::cout << "Success: " << b;
    } catch (std::exception &e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    checkSegments();
  
    testBureaucrat("Zaphod", 1);
    testBureaucrat("Arthur", 150);


    testBureaucrat("TooHigh", 0);
    testBureaucrat("TooLow", 151);

    std::cout << "--- Testing Increment/Decrement ---" << std::endl;
    try {
        Bureaucrat b("Marvin", 2);
        std::cout << "Before: " << b;
        b.incrementGrade();
        std::cout << "After Increment: " << b;
        b.incrementGrade();
    } catch (std::exception &e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Ford", 149);
        std::cout << "\nBefore: " << b;
        b.decrementGrade();
        std::cout << "After Decrement: " << b;
        b.decrementGrade();
    } catch (std::exception &e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing Orthodox Canonical Form ---" << std::endl;
    Bureaucrat original("Original", 42);
    Bureaucrat copy(original);
    Bureaucrat assigned;
    assigned = original;

    std::cout << "Original: " << original;
    std::cout << "Copy:     " << copy;
    std::cout << "Assigned: " << assigned;

    return 0;
}