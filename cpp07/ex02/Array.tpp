#include "Array.hpp"

template <class T>
Array<T>::Array() : len(0), data(0) {}

template <class T>
Array<T>::Array(unsigned int n) : len(n), data(new T[n]) {}

template <class T>
Array<T>::Array(const Array &src) {
    *this = src;
}

template <class T>
Array<T> &Array<T>::operator=(const Array &rhs) {
    if (this != rhs) {
        T *tmp = new T[rhs.len];
        for (unsigned int i = 0; i < rhs.len; i++)
            tmp[i] = rhs.data[i];
        delete[] data;
        data = tmp;
        len = rhs.len;
    }
    return *this;
}

template <class T>
const T &Array<T>::operator[](unsigned int i) const {
    if (i >= len)
        throw OutOfBoundsException();
    return data[i];
}

template <class T>
std::ostream &operator<<(std::ostream &os, const Array<T> &a) {
    for (unsigned int i = 0; i < a.size(); i++) {
        os << a[i] << "\n";
    }
    return os;
}

template <class T>
Array<T>::~Array() {
    delete[] data;
}

template <class T>
unsigned int Array<T>::size() const {
    return len;
}
