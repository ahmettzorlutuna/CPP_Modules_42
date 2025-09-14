#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
   public:
    PhoneBook();
    void add_contact(void);
    void search_contact(void) const;

   private:
    Contact _contacts[8];
    int _contact_count;
    int _next_index;
};

#endif
