/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 23:39:27 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/21 23:39:28 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <iostream>
#include <string>

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
    int N;
    
    N = 5;
    Zombie* horde = zombieHorde(N, "HordeZombie");
    if (horde == nullptr)
        return (1);
    for (int i = 0; i < N; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}