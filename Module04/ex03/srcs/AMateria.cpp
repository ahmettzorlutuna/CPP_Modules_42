/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:24:02 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/12 16:24:04 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria() : _type("default amateria") {}

AMateria::~AMateria() {}

AMateria::AMateria(AMateria const &other) : _type(other._type) {}

AMateria& AMateria::operator=(AMateria const &other)
{
    (void)other;
    return (*this);
}

AMateria::AMateria(std::string const &type) : _type(type) {}

std::string const &AMateria::getType() const
{
    return (this->_type);
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* uses " << this->_type << " on " << target.getName() << " *" << std::endl;
}




