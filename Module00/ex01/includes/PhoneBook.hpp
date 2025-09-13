#ifndef PHONEBOOK_CPP
#define PHONEBOOK_CPP

#include "Contact.hpp"

class PhoneBook {
   public:
    void add_contact(void);
    void search_contact(void) const;

   private:
    Contact contacts[8];
    int contact_count = 0;
};

#endif
