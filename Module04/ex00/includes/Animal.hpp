/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:22:04 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/11 14:22:04 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>


class Animal
{
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual void makeSound() const;
        std::string getType() const;
    protected:
        std::string _type;
};

#endif
