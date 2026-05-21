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
#include "../includes/easyfind.hpp"

int main()
{
    std::vector<int> maxVerstappenVector;
    maxVerstappenVector.push_back(33);
    maxVerstappenVector.push_back(11);
    maxVerstappenVector.push_back(44);
    maxVerstappenVector.push_back(22);

    try
    {
        std::cout << "Finding 44 in vector: ";
        std::vector<int>::iterator it = easyfind(maxVerstappenVector, 44);
        std::cout << "Found: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    try
    {
        std::cout << "Finding 99 in vector: ";
        std::vector<int>::iterator it = easyfind(maxVerstappenVector, 99);
        std::cout << "Found: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}