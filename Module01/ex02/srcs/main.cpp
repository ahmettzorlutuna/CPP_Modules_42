/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:15:59 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/22 00:15:59 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>

int main(void)
{
    std::string brain;
    
    brain = "HI THIS IS BRAIN";

    std::string* stringPtr = &brain;
    std::string& stringRef = brain;

    std::cout << "Address of brain: " << &brain << std::endl;
    std::cout << "Address held by stringPtr: " << stringPtr << std::endl;
    std::cout << "Address held by stringRef: " << &stringRef << std::endl;

    std::cout << "Value pointed to by stringPtr: " << *stringPtr << std::endl;
    std::cout << "Value pointed to by stringRef: " << stringRef << std::endl;
    return (0);
}