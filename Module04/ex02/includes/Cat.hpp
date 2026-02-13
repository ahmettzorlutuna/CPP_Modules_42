/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:22:10 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/11 14:22:10 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    public:
        Cat();
        ~Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        void makeSound() const;
        Brain* getBrain() const;
    private:
        Brain* _brain;
};

#endif
