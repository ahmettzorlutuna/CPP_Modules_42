/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:18:58 by azorlutu          #+#    #+#             */
/*   Updated: 2026/05/29 21:18:59 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

#include <cstdlib>
#include <stdexcept>
#include <utility>
#include <iomanip>

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->_vector = other._vector;
        this->_deque = other._deque;
    }
    return *this;
}

void PmergeMe::parse(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        if (arg.empty())
            throw std::invalid_argument("Error");

        for (size_t j = 0; j < arg.length(); ++j)
        {
            if (arg[j] < '0' || arg[j] > '9')
            {
                if (j == 0 && arg[j] == '+')
                    continue;
                throw std::invalid_argument("Error");
            }
        }

        long val = std::atol(arg.c_str());
        if (val < 0 || val > 2147483647)
            throw std::invalid_argument("Error");

        _vector.push_back(static_cast<int>(val));
        _deque.push_back(static_cast<int>(val));
    }
}

void PmergeMe::sortVector()
{

    if (_vector.size() < 2)
        return;
    
    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = _vector.size() % 2 != 0;
    int straggler = -1;

    if (hasStraggler)
    {
        straggler = _vector.back();
        _vector.pop_back();
    }

    for (size_t i = 0; i < _vector.size(); i += 2)
    {
        int first = _vector[i];
        int second = _vector[i + 1];
        if (first < second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
    }

    sortPairs(pairs);

    std::vector<int> mainChain;
    std::vector<int> pendingChain;

    mainChain.push_back(pairs[0].second);
    mainChain.push_back(pairs[0].first);

    for (size_t i = 1; i < pairs.size(); i++)
    {
        mainChain.push_back(pairs[i].first);
        pendingChain.push_back(pairs[i].second);
    }

    std::vector<size_t> jacobsthalSequence = createJacobsthalSequence(pendingChain.size());

    for (size_t i = 0; i < jacobsthalSequence.size(); i++)
    {
        size_t pendingIndex = jacobsthalSequence[i];
        int value = pendingChain[pendingIndex];

        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(it, value);
    }

    if (hasStraggler)
    {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }
    
    _vector = mainChain;
}

void PmergeMe::sortPairs(std::vector<std::pair<int, int> > &pairs)
{
    for (size_t i = 1; i < pairs.size(); i++)
    {
        std::pair<int, int> key = pairs[i];
        size_t j = i;
        while(j > 0 && pairs[j - 1].first > key.first)
        {
            pairs[j] = pairs[j - 1];
            j--;
        }
        pairs[j] = key;
    }
}

std::vector<size_t> PmergeMe::createJacobsthalSequence(size_t pendingSize)
{
    std::vector<size_t> sequence;
    if(pendingSize == 0)
        return sequence;
    
    size_t lastJacobsthal = 1;
    size_t currentJacobsthal = 3;

    while (sequence.size() < pendingSize)
    {
        size_t startIndex = currentJacobsthal - 2;

        if(startIndex >= pendingSize)
            startIndex = pendingSize - 1;

        size_t limit = lastJacobsthal - 1;

        for (int i = static_cast<int>(startIndex); i >= static_cast<int>(limit); i--)
        {
            sequence.push_back(static_cast<size_t>(i));
        }
        
        size_t nextJacobsthal = currentJacobsthal + 2 * lastJacobsthal;
        lastJacobsthal = currentJacobsthal;
        currentJacobsthal = nextJacobsthal;
    }
    return sequence;
}

void PmergeMe::sortDeque()
{
    if (_deque.size() < 2)
        return;
    
    std::deque<std::pair<int, int> > pairs;
    bool hasStraggler = _deque.size() % 2 != 0;
    int straggler = -1;

    if (hasStraggler)
    {
        straggler = _deque.back();
        _deque.pop_back();
    }

    for (size_t i = 0; i < _deque.size(); i += 2)
    {
        int first = _deque[i];
        int second = _deque[i + 1];
        if (first < second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
    }

    sortPairs(pairs);

    std::deque<int> mainChain;
    std::deque<int> pendingChain;

    mainChain.push_back(pairs[0].second);
    mainChain.push_back(pairs[0].first);

    for (size_t i = 1; i < pairs.size(); i++)
    {
        mainChain.push_back(pairs[i].first);
        pendingChain.push_back(pairs[i].second);
    }

    std::vector<size_t> jacobsthalSequence = createJacobsthalSequence(pendingChain.size());

    for (size_t i = 0; i < jacobsthalSequence.size(); i++)
    {
        size_t pendingIndex = jacobsthalSequence[i];
        int value = pendingChain[pendingIndex];

        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(it, value);
    }

    if (hasStraggler)
    {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }
    
    _deque = mainChain;
}

void PmergeMe::sortPairs(std::deque<std::pair<int, int> > &pairs)
{
    for (size_t i = 1; i < pairs.size(); i++)
    {
        std::pair<int, int> key = pairs[i];
        size_t j = i;
        while(j > 0 && pairs[j - 1].first > key.first)
        {
            pairs[j] = pairs[j - 1];
            j--;
        }
        pairs[j] = key;
    }
}

void PmergeMe::sort(int argc, char **argv)
{
    parse(argc, argv);

    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); i++)
    {
        std::cout << _vector[i] << " ";
    }
    std::cout << std::endl;

    clock_t startVector = clock();

    sortVector();

    clock_t endVector = clock();

    double vectorTime = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000.0;

    clock_t startDeque = clock();

    sortDeque();

    clock_t endDeque = clock();

    double dequeTime = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000.0;

    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); i++)
    {
        std::cout << _vector[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << std::fixed << std::setprecision(5) << dequeTime << " us" << std::endl;
}