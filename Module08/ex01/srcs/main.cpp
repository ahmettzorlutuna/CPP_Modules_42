/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:59:15 by azorlutu          #+#    #+#             */
/*   Updated: 2026/05/17 16:59:16 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../includes/Span.hpp"

int main()
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    std::cout << std::endl;

    try
    {
        sp.addNumber(42);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    Span span2 = Span(5);

    span2.addNumber(34);
    try
    {
        span2.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    Span bigSpan = Span(100000);

    std::vector<int> randomNumbers;

    srand(time(NULL));
    for (int i = 0; i < 100000; i++)
    {
        randomNumbers.push_back(rand());
    }
    
    try
    {
        bigSpan.addNumbers(randomNumbers.begin(), randomNumbers.end());
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span : " << bigSpan.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}