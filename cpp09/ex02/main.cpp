#include "PmergeMe.hpp"
#include "utils.hpp"
#include <iostream>
#include <exception>
#include <vector>
#include <ctime>

void runVec(char** arg) {
    clock_t start = clock();
    std::vector<int> vec;
    try {
        vec = parseVec(arg);
        PmergeMe vc(vec);
    } catch(const std::exception& e) {
        throw e;
    }
    clock_t end = clock();
    double us = static_cast<double>((end - start) / CLOCKS_PER_SEC * 1000000);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << us << " us" << std::endl; 
}

int main(int ac, char** av) {
    if(ac < 2) {
        std::cerr << "Program should run as: ./PmergeMe 2 3 4" << std::endl; 
    }
    try {
        runVec(&(av[1]));
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    
}