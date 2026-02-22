/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:06:22 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/22 15:06:23 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(Intern const &other);
        Intern &operator=(Intern const &other);

        AForm *makeForm(const std::string &formName, const std::string &target);
    private:
        AForm *createShrubberyCreationForm(const std::string &target);
        AForm *createRobotomyRequestForm(const std::string &target);
        AForm *createPresidentialPardonForm(const std::string &target);
};

#endif