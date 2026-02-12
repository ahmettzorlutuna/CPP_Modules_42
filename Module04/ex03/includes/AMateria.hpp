/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:24:16 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/12 16:24:17 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

#include <iostream>

class ICharacter;

class AMateria {
    public:
        AMateria ();
        virtual ~AMateria();
        AMateria(AMateria const &other);
        AMateria& operator=(AMateria const &other);

        AMateria(std::string const &type);
        std::string const &getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter &target);
    protected:
        std::string _type;
};

#endif