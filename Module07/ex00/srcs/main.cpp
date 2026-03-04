/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:21:14 by azorlutu          #+#    #+#             */
/*   Updated: 2026/03/03 22:21:15 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../includes/whatever.hpp"

class Awesome {
public:
    Awesome(void) : number(0) {}
    Awesome(int n) : number(n) {}
    Awesome & operator=(Awesome & a) { number = a.number; return *this; }
    bool operator==(Awesome const & rhs) const { return (this->number == rhs.number); }
    bool operator!=(Awesome const & rhs) const { return (this->number != rhs.number); }
    bool operator>(Awesome const & rhs) const { return (this->number > rhs.number); }
    bool operator<(Awesome const & rhs) const { return (this->number < rhs.number); }
    bool operator>=(Awesome const & rhs) const { return (this->number >= rhs.number); }
    bool operator<=(Awesome const & rhs) const { return (this->number <= rhs.number); }
    int get_n() const { return number; }
private:
    int number;
};

std::ostream & operator<<(std::ostream & o, const Awesome & a) { o << a.get_n(); return o; }

int main(void) {
    // 1. SUBJECT ÖRNEĞİ (ZORUNLU TEST)
    std::cout << "--- Subject Tests ---" << std::endl;
    int a = 2;
    int b = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    // 2. EŞİTLİK DURUMU TESTİ (Subject kuralı: Eşitse ikinci döner)
    std::cout << "\n--- Equality Rule Test ---" << std::endl;
    int e = 42;
    int f = 42;
    std::cout << "Addresses: e=" << &e << ", f=" << &f << std::endl;
    std::cout << "min(42, 42) returns address: " << &::min(e, f) << " (should be f's address)" << std::endl;

    // 3. KARMAŞIK TİP TESTİ (Awesome Class)
    std::cout << "\n--- Complex Type Test (Class) ---" << std::endl;
    Awesome a_obj(10), b_obj(20);
    ::swap(a_obj, b_obj);
    std::cout << "a_obj: " << a_obj << ", b_obj: " << b_obj << std::endl;
    std::cout << "min(a_obj, b_obj): " << ::min(a_obj, b_obj) << std::endl;
    std::cout << "max(a_obj, b_obj): " << ::max(a_obj, b_obj) << std::endl;

    return 0;
}