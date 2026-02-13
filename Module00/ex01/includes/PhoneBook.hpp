/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:46:40 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/20 23:46:41 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
   public:
    PhoneBook();
    void add_contact(void);
    void search_contact(void) const;
    void search_detail(const std::string& command) const;

   private:
    Contact _contacts[8];
    int _contact_count;
    int _next_index;
};

#endif
