/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:47:53 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/12 17:47:55 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character() : _name("default character"), _floorCount(0)
{
    for (int i = 0; i < 4; i++)
    {
        _inventory[i] = NULL;
    }
}

Character::~Character() {
    for (int i = 0; i < 4; i++)
        if (_inventory[i])
            delete _inventory[i];
    for (int i = 0; i < _floorCount; i++)
        if (_floor[i])
            delete _floor[i];
}

Character::Character(Character const &other)
{
    _name = other._name;
    _floorCount = 0;
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

Character& Character::operator=(Character const &other)
{
    if (this != &other)
    {
        _name = other._name;
        for (int i = 0; i < 4; i++) {
            if (_inventory[i])
                delete _inventory[i];
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
        for (int i = 0; i < _floorCount; i++)
            if (_floor[i])
                delete _floor[i];
        _floorCount = 0;
    }
    return *this;
}

Character::Character(std::string const &name) : _name(name), _floorCount(0)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

std::string const &Character::getName() const
{
    return this->_name;
}

void Character::    equip(AMateria* materia)
{
    if(!materia) return;

    for (int i = 0; i < 4; i++) {
        if(_inventory[i] == materia)
        {
            std::cout << "Materia already equipped." << std::endl;
            return;
        }
        if (_inventory[i] == NULL) {
            _inventory[i] = materia;
            return;
        }
    }

    if (this->_floorCount < 100) {
        std::cout << "Inventory full. Storing materia on the floor." << std::endl;
        this->_floor[this->_floorCount++] = materia;
    }
    else {
        std::cout << "Floor is also full. Materia deleted to prevent memory leak." << std::endl;
        delete materia;
    }
}

void Character::unequip(int index)
{
    if (index >= 0 && index < 4 && _inventory[index] != NULL && _floorCount < 100)
    {
        this->_floor[_floorCount++] = _inventory[index];
        _inventory[index] = NULL;
    }
}

void Character::use(int index, ICharacter &target)
{
    if (index >= 0 && index < 4 && _inventory[index] != NULL)
        _inventory[index]->use(target);
}
