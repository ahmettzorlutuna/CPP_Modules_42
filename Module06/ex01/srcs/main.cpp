/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:24:41 by azorlutu          #+#    #+#             */
/*   Updated: 2026/03/03 20:24:42 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

#include <iostream>

int main()
{
    Data data;
    data.setValue(42);

    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "Original value: " << data.getValue() << std::endl;
    std::cout << "Original address: " << &data << std::endl;
    std::cout << "Serialized value: " << serialized << std::endl;
    std::cout << "Serialized address: " << &serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized value: " << deserialized->getValue() << std::endl;
    std::cout << "Deserialized address: " << deserialized << std::endl;
    return 0;
}