/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:09:06 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/11 17:09:07 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        this->_ideas[i] = other._ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        {
            this->_ideas[i] = other._ideas[i];
        }
    }
    return *this;
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
    {
        this->_ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
    {
        return this->_ideas[index];
    }
    return "";
}