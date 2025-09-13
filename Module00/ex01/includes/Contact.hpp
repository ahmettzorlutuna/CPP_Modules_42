#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
   public:
	Contact();
	void setAllFields(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
	bool isSet() const;

    std::string get_first_name(void) const;
    std::string get_last_name(void) const;
    std::string get_nickname(void) const;
    std::string get_phone_number(void) const;
    std::string get_darkest_secret(void) const;
	
    private:
		bool _isSet;
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
};

#endif
