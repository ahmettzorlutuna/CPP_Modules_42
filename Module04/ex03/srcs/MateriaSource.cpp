/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:05:33 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/12 18:05:34 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        learned[i] = NULL;
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (learned[i]) {
            delete learned[i];
        }
    }
}

MateriaSource::MateriaSource(MateriaSource const &other) {
    for (int i = 0; i < 4; i++) {
        if (other.learned[i]){
            learned[i] = other.learned[i]->clone();
        } else {
            learned[i] = NULL;
        }
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource const &other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (learned[i]) 
                delete learned[i];
            if (other.learned[i]) {
                learned[i] = other.learned[i]->clone();
            } else {
                learned[i] = NULL;
            }
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if(m == NULL) {
            return;
        }
        if (learned[i] == NULL) {
            learned[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (learned[i] && learned[i]->getType() == type) {
            return learned[i]->clone();
        }
    }
    return NULL;
}


