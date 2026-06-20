#ifndef ARRAY_HPP
# define ARRAY_HPP

template <class T>
class Array
{
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &src);
        Array &operator=(const Array &rhs);
        ~Array();
        
        unsigned int size();
        T& operator[](unsigned int index);

    private:
        T* arr;
        unsigned int n;
};

#endif
