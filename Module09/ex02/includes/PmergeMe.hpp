/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:19:10 by azorlutu          #+#    #+#             */
/*   Updated: 2026/05/29 21:19:12 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <ctime>

class PmergeMe
{
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        void sort(int argc, char **argv);
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
        void parse(int argc, char **argv);
        void sortVector();
        void sortDeque();
        void sortPairs(std::vector<std::pair<int, int> >& pairs);
        void sortPairs(std::deque<std::pair<int, int> >& pairs);
        std::vector<size_t> createJacobsthalSequence(size_t pendingSize);
};

#endif