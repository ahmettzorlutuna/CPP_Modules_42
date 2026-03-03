/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:21:24 by azorlutu          #+#    #+#             */
/*   Updated: 2026/03/03 22:21:24 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/whatever.hpp"

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(const T& a, const T& b)
{
    if(a < b)
        return a;
    else
        return b;
}

template <typename T>
T max(const T& a, const T& b)
{
    if(a > b)
        return a;
    else
        return b;
}