#include "Array.hpp"
#include "Test.hpp"

#include <iostream>

int main() {
    Array<Test> *a = new Array<Test>(5);
    Array<Test> *b = new Array<Test>();
    Array<Test> *c = new Array<Test>(1);


    std::cout <<"*a------------------------------------------------" << std::endl;
    std::cout << *a << std::endl;
    std::cout <<"(*a)[0]----------------------------------------------" << std::endl;
    std::cout << (*a)[0] << std::endl;
    std::cout <<"*b------------------------------------------------" << std::endl;
    std::cout << *b << std::endl;
    std::cout <<"*c------------------------------------------------" << std::endl;
    std::cout << *c << std::endl;
    std::cout <<"(*c)[0]----------------------------------------------" << std::endl;
    std::cout << (*c)[0] << std::endl;


    try {
        std::cout << (*a)[5] << std::endl;
        std::cout << (*b)[5] << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        // delete a;
        // delete b;
        // delete c;
        throw;
    }

    delete a;
    delete b;
    delete c;
}