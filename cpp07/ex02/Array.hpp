#ifndef ARRAY_HPP
#define ARRAY_HPP

template <class T>
class Array {
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& src);
        Array &operator=(const Array& rhs);
        ~Array();
    
        size_t size();
        

    private:
        T  
}


#endif