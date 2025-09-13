#include "Contact.hpp"

Contact::Contact() : _isSet(false) {}

bool Contact :: isSet() const {
    return this->_isSet;
}

void Contact::setAllFields(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds) {
    this->_first_name = fn;
    this->_last_name = ln;
    this->_nickname = nn;
    this->_phone_number = pn;
    this->_darkest_secret = ds;
}