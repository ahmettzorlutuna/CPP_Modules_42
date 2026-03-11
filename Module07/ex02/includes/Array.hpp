/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 23:05:06 by azorlutu          #+#    #+#             */
/*   Updated: 2026/03/04 23:05:07 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <exception>

template <typename T>
class Array
{
    public:
        Array() : _size(0), _elements(NULL) {};
        ~Array(){
            delete[] _elements;
        };
        Array(const Array& other){
            _size = other._size;
            _elements = new T[_size];
            for (unsigned int i = 0; i < _size; i++){
                _elements[i] = other._elements[i];
            }
        };
        Array& operator=(const Array& other){
            if(this != &other)
            {
                if(_elements)
                    delete[] _elements;
                _size = other._size;
                if(_size > 0)
                {
                    _elements = new T[_size];
                    for (unsigned int i = 0; i < _size; i++)
                        _elements[i] = other._elements[i];
                }else{
                    _elements = NULL;
                }
            }
            return *this;
        };
        Array(unsigned int n) : _size(n), _elements(new T[n]()) {};
        class MyVeryVeryHandsomeMaxEmilianVerstappenOutOfRangeExceptionClassThatNeverExistBeforeLetsGetItSimplyLovely: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Error:  Index out of bounds!";
                }
        };
        T& operator[](unsigned int index){
            if(index >= _size || _elements == NULL)
                throw MyVeryVeryHandsomeMaxEmilianVerstappenOutOfRangeExceptionClassThatNeverExistBeforeLetsGetItSimplyLovely();
            return _elements[index];
        }
        const T& operator[](unsigned int index) const
        {
            if(index >= _size || _elements == NULL)
                throw MyVeryVeryHandsomeMaxEmilianVerstappenOutOfRangeExceptionClassThatNeverExistBeforeLetsGetItSimplyLovely();
            return _elements[index];
        }
        unsigned int size() const{
            return _size;
        }
    private:
        unsigned int _size;
        T* _elements;
};