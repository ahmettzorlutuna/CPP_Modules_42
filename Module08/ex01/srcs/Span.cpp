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

#include "../includes/Span.hpp"

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

unsigned int Span::shortestSpan() const
{
    unsigned int diff;

    if(_numbers.size() < 2)
        throw NotEnoughNumbersException();
    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    unsigned int minSpan = static_cast<unsigned int>(sortedNumbers[1] - sortedNumbers[0]);
    for (size_t i = 1; i < sortedNumbers.size() - 1; ++i)
    {
        diff = static_cast<unsigned int>(sortedNumbers[i + 1] - sortedNumbers[i]);
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if(_numbers.size() < 2)
        throw NotEnoughNumbersException();

    std::vector<int>::const_iterator intMin = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator intMax = std::max_element(_numbers.begin(), _numbers.end());

    return (static_cast<unsigned int>(*intMax) - static_cast<unsigned int>(*intMin));
}

const char* Span::SpanFullException::what() const throw()
{
    return "Span is full. Cannot add more numbers.";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
    return "Not enough numbers to calculate a span.";
}