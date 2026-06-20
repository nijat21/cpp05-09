#include "Array.hpp"
#include <stdexcept>
#include <cstddef>

template <class T>
Array<T>::Array() : arr(NULL), n(0) {}

template <class T>
Array<T>::Array(unsigned int n) : arr(new T[n]), n(n) {}

template <class T>
Array<T>::Array(const Array &src) : arr(new T[src.n]), n(src.n)
{
    for(unsigned int i = 0; i < n; i++) 
        arr[i] = src.arr[i];
}

template <class T>
Array<T>& Array<T>::operator=(const Array &rhs)
{
    if (this != &rhs)
    {
       delete[] arr;
       n = rhs.n;
       arr = new T[n];
       for(unsigned int i = 0; i < n; i++)
           arr[i] = rhs.arr[i];
    }
    return (*this);
}

template <class T>
Array<T>::~Array()
{
    delete[] arr;
}

template <class T>
unsigned int Array<T>::size() {
    return n;
}

template <class T>
T& Array<T>::operator[](unsigned int index) {
    if(index >= n)
        throw std::out_of_range("Array index is out of bounds!");
    return arr[index];
}

