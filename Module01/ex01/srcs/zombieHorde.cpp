/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 23:39:41 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/21 23:39:42 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <iostream>
#include <string>

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
    {
        std::cout << "Error: N must be greater than 0." << std::endl;
        return nullptr;
    }
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        horde[i] = Zombie(name + "_" + std::to_string(i + 1));
    }
    return horde;
}