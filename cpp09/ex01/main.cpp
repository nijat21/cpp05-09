#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Program should be run as ./RPN \"1 6 3 25 3\"" << std::endl;
        return 1;
    }

    try {
        RPN a(av[1]);

        // std::cout << std::endl;
        a.printResult();

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}