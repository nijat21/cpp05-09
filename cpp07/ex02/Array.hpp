#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <class T>
class Array {
  public:
    Array();
    Array(unsigned int n);
    Array(const Array &src);
    Array &operator=(const Array &rhs);
    const T &operator[](unsigned int i);
    ~Array();

    unsigned int size() const;

    class OutOfBoundsException : public std::exception {
      public:
        virtual const char *what() const throw() {
            return "Index is out of bounds";
        };
    };

  private:
    T *data;
    unsigned int len;
};

#include "Array.tpp"

#endif
