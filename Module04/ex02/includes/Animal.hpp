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


class AAnimal
{
    public:
        AAnimal();
        virtual ~AAnimal();
        AAnimal(const AAnimal& other);
        AAnimal& operator=(const AAnimal& other);
        virtual void makeSound() const = 0;
        std::string getType() const;
    protected:
        std::string _type;
};

#endif
