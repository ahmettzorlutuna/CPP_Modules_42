/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:47:25 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/20 23:47:25 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if(argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            for (int j = 0; argv[i][j]; j++)
            {
                char upper_char = std::toupper(argv[i][j]);
                std::cout << upper_char;
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    return (0);
}
