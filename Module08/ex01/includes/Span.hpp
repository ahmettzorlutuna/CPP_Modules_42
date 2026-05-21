/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:59:37 by azorlutu          #+#    #+#             */
/*   Updated: 2026/05/17 16:59:47 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>

class Span
{
    public:
        Span();
        ~Span();
        Span(const Span& other);
        Span& operator=(const Span& other);
        Span(unsigned int N);
        void addNumber(int number);
        template <typename T>
        void addNumbers(T first, T last);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
        class SpanFullException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class NotEnoughNumbersException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
    private:
        std::vector<int> _numbers;
        unsigned int _maxSize;
};

#endif