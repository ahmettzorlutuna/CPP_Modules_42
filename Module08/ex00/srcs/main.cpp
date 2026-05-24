/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:47:29 by azorlutu          #+#    #+#             */
/*   Updated: 2026/05/17 15:47:30 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "../includes/easyfind.hpp"

int main()
{
    std::vector<int> vec;

    for (int i = 1; i <= 5; ++i)
    {
        vec.push_back(i * 10);
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        it = easyfind(vec, 99);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(42);
    lst.push_back(10);
    lst.push_back(42);

    try {
        std::list<int>::iterator it = easyfind(lst, 42);
        *it = 99; 
        for(std::list<int>::iterator i = lst.begin(); i != lst.end(); ++i)
            std::cout << *i << " ";
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::deque<int> dq;

    try {
        std::deque<int>::iterator it = easyfind(dq, 10);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}