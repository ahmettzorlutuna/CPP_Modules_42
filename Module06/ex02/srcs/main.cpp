/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 21:01:02 by azorlutu          #+#    #+#             */
/*   Updated: 2026/03/03 21:01:03 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"
#include <iostream>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << "--- Testing identify functions ---" << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << "\nTest #" << i + 1 << ":" << std::endl;
        
        Base* ptr = generate();
        
        if (ptr) {
            identify(ptr);
            identify(*ptr);

            delete ptr;
        }
        std::cout << "---------------------------------" << std::endl;
    }

    std::cout << "\n--- Testing NULL Pointer ---" << std::endl;
    identify(static_cast<Base*>(NULL));

    return 0;
}