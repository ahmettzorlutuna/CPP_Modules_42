/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 22:01:46 by azorlutu          #+#    #+#             */
/*   Updated: 2026/03/04 22:01:47 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

#include <iostream>

template <typename T>
void printElement(const T & n)
{
    std::cout << n << std::endl;
}

int main()
{
    int numArr[] = {1, 2, 3};
    ::iter(numArr, ARRAY_SIZE(numArr), printElement);

    std::string strArr[] = {"MAX", "VERSTAPPEN"};
    ::iter(strArr, ARRAY_SIZE(strArr), printElement);

    const char* strArr2[] = {"AHMET", "ZORLUTUNA"};
    ::iter (strArr2, ARRAY_SIZE(strArr2), printElement);
}