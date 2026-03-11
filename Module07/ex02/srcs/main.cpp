/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 23:04:44 by azorlutu          #+#    #+#             */
/*   Updated: 2026/03/04 23:04:45 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

#include <iostream>

int main(void)
{
    Array<int> empty;
    std::cout << empty.size() << std::endl;
    
    Array<int> numbers(5);
    std::cout << numbers.size() << std::endl;

    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = i * 2;
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }

    Array<int> copy = numbers;

    std::cout << "Original[0]: " << numbers[0] << std::endl;
    std::cout << "Copy[0]: " << copy[0] << std::endl;

    numbers[0] = 777;

    std::cout << "Original[0]: " << numbers[0] << std::endl;
    std::cout << "Copy[0]: " << copy[0] << std::endl;

    try {
        std::cout << numbers[10] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}