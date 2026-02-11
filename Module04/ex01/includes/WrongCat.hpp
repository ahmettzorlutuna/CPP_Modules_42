/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:22:42 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/11 14:22:43 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "../includes/WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat& other);
        WrongCat& operator=(const WrongCat& other);
        void makeSound() const;
};

#endif