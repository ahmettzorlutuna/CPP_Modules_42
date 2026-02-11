/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:22:15 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/11 14:22:15 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal
{
    public:
        Dog();
        ~Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        void makeSound() const;
    private:
        Brain* _brain;
};

#endif
