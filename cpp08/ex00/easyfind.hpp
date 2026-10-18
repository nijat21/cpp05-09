#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

template <typename T> typename T::iterator easyfind(const T &cont, const int val);

class NotFoundException : public std::exception {
    const char *what() const throw() {
        return "Value not found!";
    }
};

#include "easyfind.tpp"

#endif