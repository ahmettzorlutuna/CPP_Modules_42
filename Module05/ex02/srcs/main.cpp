/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:34:12 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/18 15:34:13 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(std::time(NULL));

    Bureaucrat boss("boss", 1);
    Bureaucrat manager("manager", 40);
    Bureaucrat intern("arthur", 150);

    ShrubberyCreationForm shrub("shrub");      // Sign: 145, Exec: 137
    RobotomyRequestForm robo("robo");         // Sign: 72, Exec: 45
    PresidentialPardonForm pardon("pardon");    // Sign: 25, Exec: 5

    std::cout << "\n--- TEST 1: The Struggling Intern ---" << std::endl;

    intern.signForm(shrub);
    intern.executeForm(shrub);

    std::cout << "\n--- TEST 2: Shrubbery ---" << std::endl;

    manager.signForm(shrub);
    manager.executeForm(shrub);

    std::cout << "\n--- TEST 3: Robotomy ---" << std::endl;

    manager.signForm(robo);
    manager.executeForm(robo);
    manager.executeForm(robo);
    manager.executeForm(robo);

    std::cout << "\n--- TEST 4: Presidential Pardon ---" << std::endl;

    manager.signForm(pardon);
    
    boss.signForm(pardon);
    boss.executeForm(pardon);

    std::cout << "\n--- TEST 5: Unsigned Form Execution ---" << std::endl;
    RobotomyRequestForm unsignedForm("TargetX");
    boss.executeForm(unsignedForm);

    return 0;
}