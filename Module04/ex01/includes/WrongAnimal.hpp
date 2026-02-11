/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:22:33 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/11 14:22:34 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);
        void makeSound() const;
        std::string getType() const;
    protected:
        std::string _type;
};

#endif