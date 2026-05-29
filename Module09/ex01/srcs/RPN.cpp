/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 19:50:51 by azorlutu          #+#    #+#             */
/*   Updated: 2026/05/29 19:50:52 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

#include <sstream>

RPN::RPN()
{

}

RPN::~RPN()
{

}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    if(this != &other)
    {
        this->_stack = other._stack;
    }
    return *this;
}

void RPN::calculate(const std::string& expression)
{
    for(size_t i = 0; i < expression.length(); i++)
    {
        char c = expression[i];

        if(c == ' ')
            continue;
        else if(c >= '0' && c <= '9')
            _stack.push(c - '0');
        else if(c == '+' || c == '-' || c == '*' || c == '/')
        {
            if(_stack.size() < 2)
                throw std::runtime_error("Error");
            
            int secondValue = _stack.top();
            _stack.pop();
            int firstValue = _stack.top();
            _stack.pop();

            if(c == '+')
                _stack.push(firstValue + secondValue);
            else if(c == '-')
                _stack.push(firstValue - secondValue);
            else if(c == '*')
                _stack.push(firstValue * secondValue);
            else if(c == '/')
            {
                if(secondValue == 0)
                    throw std::runtime_error("Error");
                _stack.push(firstValue / secondValue);
            }
        }
        else
            throw std::runtime_error("Error");
    }
    if(_stack.size() == 1)
        std::cout << _stack.top() << std::endl;
    else
        throw std::runtime_error("Error");
}