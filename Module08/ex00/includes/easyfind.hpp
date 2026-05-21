/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:47:43 by azorlutu          #+#    #+#             */
/*   Updated: 2026/05/17 15:47:44 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>

class MaxVerstappenNotFoundException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Value not found in the container";
        }
};

template <typename T>

typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw MaxVerstappenNotFoundException();
    return it;
}

#endif
