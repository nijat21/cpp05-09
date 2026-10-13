#include "Array.hpp"

template <class T>
Array<T>::Array() : len(0) {
    return new T[];
}

template <class T>
Array<T>::Array(unsigned int n) : len(n) {
    return new T[n];
}

template <class T>
Array<T>::Array(const Array &src) {
    *this = src;
}

template <class T>
Array<T> &Array<T>::operator=(const Array &rhs) {
    if (*this != rhs) {
        for (unsigned int i = 0; i < len; i++)
            this->data[i] = new T(rhs[i]);
    }
}

template <class T>
const T &Array<T>::operator[](unsigned int i) {
    if (i < 0 || i > len - 1)
        throw OutOfBoundsException();
    return data[i];
}

template <class T>
Array<T>::~Array() {
    delete[] data;
}

template <class T>
unsigned int Array<T>::size() const {
    return len;
}
