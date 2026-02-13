/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:41:43 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/23 19:41:43 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main(int argc, char **argv)
{
    Harl    harl;

    if (argc != 2)
    {
        std::cout << "Usage: ./harlFilter <level>" << std::endl;
        return (1);
    }
    std::string level = argv[1];
    harl.complain(level);
    return (0);
}