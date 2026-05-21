/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:59:27 by azorlutu          #+#    #+#             */
/*   Updated: 2026/05/17 16:59:28 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::~Span() {}

Span::Span(const Span& other) : _numbers(other._numbers), _maxSize(other._maxSize) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _numbers = other._numbers;
        _maxSize = other._maxSize;
    }
    return *this;
}

Span::Span(unsigned int N) : _maxSize(N) {}

void Span::addNumber(int number)
{
    if(_numbers.size() >= _maxSize)
        throw SpanFullException();
    _numbers.push_back(number);
}

template <typename T>
void Span::addNumbers(T first, T last)
{
    while (first != last)
    {
        addNumber(*first);
        ++first;
    }
}

// [3, 6, 11, 15];

unsigned int Span::shortestSpan() const
{
    unsigned int minSpan;

    if(_numbers.size() < 2)
        throw NotEnoughNumbersException();
    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    minSpan = sortedNumbers[1] - sortedNumbers[0];
    for (size_t i = 1; i < sortedNumbers.size() - 1; ++i)
    {
        unsigned int span = sortedNumbers[i + 1] - sortedNumbers[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}