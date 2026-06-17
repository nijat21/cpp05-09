#ifndef ITER_HPP
#define ITER_HPP

#include "Test.hpp"
#include <iostream>

template <class T>
void printConst(const T& curr) {
    std::cout << curr << std::endl;
}

template <class T>
void printNonConst(T& curr) {
    std::cout << curr << std::endl;
}

template <class T, class F>
void iter(T* arr, const int len, F f) {
    for(int i = 0; i < len; i++) 
        f(arr[i]);
}

#endif
