#include "Array.hpp"
#include "Array.tpp"
#include <iostream>

int main()
{
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i;

    Array<int> b(a);    
    b[0] = 999;
    std::cout << a[0] << " " << b[0] << std::endl;

    Array<int> c;
    c = a;
    c[1] = 888;
    std::cout << a[1] << " " << c[1] << std::endl;

    try {
        std::cout << a[100] << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

