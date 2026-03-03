/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:26:49 by azorlutu          #+#    #+#             */
/*   Updated: 2026/03/03 20:26:50 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

class Data
{
    public:
        Data();
        ~Data();
        Data(const Data& other);
        Data& operator=(const Data& other);
        int getValue() const;
        void setValue(int value);
    private:
        int value;
};

#endif