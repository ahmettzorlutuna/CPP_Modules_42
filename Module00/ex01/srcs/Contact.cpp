/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:41:30 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/20 23:41:31 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"
#include <iostream>

Contact::Contact(){
    this->_isSet = false;
    this->_first_name = "";
    this->_last_name = "";
    this->_nickname = "";
    this->_phone_number = "";
    this->_darkest_secret = "";
}

bool Contact::isSet() const {
    return _isSet;
}

void Contact::setAllFields(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds){
    _first_name = fn;
    _last_name = ln;
    _nickname = nn;
    _phone_number = pn;
    _darkest_secret = ds;
    _isSet = true;
}

std::string Contact::get_first_name(void) const {
    return _first_name;
}

std::string Contact::get_last_name(void) const {
    return _last_name;
}

std::string Contact::get_nickname(void) const {
    return _nickname;
}

std::string Contact::get_phone_number(void) const {
    return _phone_number;
}

std::string Contact::get_darkest_secret(void) const {
    return _darkest_secret;
}
