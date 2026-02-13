/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:31:02 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/12 16:31:03 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
    public:
        Ice();
        ~Ice();
        Ice(Ice const &other);
        Ice& operator=(Ice const &other);

        AMateria* clone() const;
        void use(ICharacter &target);
};

#endif