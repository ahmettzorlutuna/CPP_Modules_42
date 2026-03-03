/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:27:00 by azorlutu          #+#    #+#             */
/*   Updated: 2026/03/03 20:27:00 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"

Data::Data() : value(0)
{
}

Data::~Data()
{
}

Data::Data(const Data& other) : value(other.value)
{
}

Data& Data::operator=(const Data& other)
{
    if (this != &other)
    {
        value = other.value;
    }
    return *this;
}

int Data::getValue() const
{
    return value;
}

void Data::setValue(int value)
{
    this->value = value;
}