/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:38:09 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/21 20:38:10 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <iostream>
#include <string>

void randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}