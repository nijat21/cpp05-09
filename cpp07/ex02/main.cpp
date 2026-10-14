#include "Array.hpp"
#include "Test.hpp"

#include <iostream>

int main() {
    Array<Test> *a = new Array<Test>(5);
    Array<Test> *b = new Array<Test>();

    std::cout << b << std::endl;
    (void)a;
}