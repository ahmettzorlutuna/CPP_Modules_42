/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 22:01:58 by azorlutu          #+#    #+#             */
/*   Updated: 2026/03/04 22:02:00 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

template <typename T>
void iter(T *array, size_t length, void(*f)(T &))
{
    std::cout << "Non Const Iter Function Worked !" << std::endl;
    if(!array || !f)
        return;
    for (size_t i = 0; i < length; i++)
    {
        f(array[i]);
    }
}

template <typename T>
void iter(const T *array, size_t length, void(*f)(const T&))
{
    std::cout << "Const Iter Function Worked !" << std::endl;
    if(!array || !f)
        return;
    for(size_t i = 0; i < length; i++)
    {
        f(array[i]);
    }
}