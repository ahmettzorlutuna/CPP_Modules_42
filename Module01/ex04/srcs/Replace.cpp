/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:11:23 by azorlutu          #+#    #+#             */
/*   Updated: 2026/01/22 22:11:24 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Replace.hpp"

#include <string>

void    myReplace(std::string& content, const std::string& s1, const std::string& s2)
{
    size_t cursor;

    cursor  = 0;

    if(s1.empty()) return;

    cursor = content.find(s1,cursor);

    while (cursor != std::string::npos)
    {
        content.erase(cursor, s1.length());
        content.insert(cursor, s2);
        cursor += s2.length();
        cursor = content.find(s1,cursor);
    }
}