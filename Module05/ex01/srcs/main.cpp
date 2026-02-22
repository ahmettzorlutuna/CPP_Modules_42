/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:02:58 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/17 13:02:58 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main() {

    std::cout << "========== EX01: FORM TESTS ==========" << std::endl;

    std::cout << "\n--- Test 1: Invalid Form Construction ---" << std::endl;
    try {
        Form f1("High-Level Form", 0, 15);
    } catch (std::exception &e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    try {
        Form f2("Low-Level Form", 151, 150);
    } catch (std::exception &e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Successful Signing ---" << std::endl;

    try {
        Bureaucrat boss("Zaphod", 5);
        Form taxForm("Tax Return", 25, 50);

        std::cout << boss << std::endl;
        std::cout << taxForm << std::endl;

        boss.signForm(taxForm);
        std::cout << "After signing: " << taxForm << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Insufficient Grade to Sign ---" << std::endl;
    try {
        Bureaucrat intern("Arthur", 140);
        Form topSecret("Top Secret Document", 10, 5);

        std::cout << intern << std::endl;
        std::cout << topSecret << std::endl;

        intern.signForm(topSecret);
        std::cout << "Status: " << topSecret << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Unexpected catch in main: " << e.what() << std::endl;
    }

    // 4. Tekrar İmzalama Testi
    std::cout << "\n--- Test 4: Already Signed Form ---" << std::endl;
    try {
        Bureaucrat manager("Ford", 20);
        Form permit("Building Permit", 30, 30);

        manager.signForm(permit);
        manager.signForm(permit);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}