#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

void testSubj() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
}

void testExcepts() {
    Span sp = Span(1);

    try {
        sp.addNumber(0);
        sp.shortestSpan();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        sp.longestSpan();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        int arr[] = {0, 9, 3, 4, 1};
        std::vector<int> v(arr, arr + 5);
        sp.addRange(v.begin(), v.end());
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        sp.addNumber(1);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void testTenKAddNumber() {
    try {
        Span sp = Span(10001);
        for (int i = 0; i < 10001; i++)
            sp.addNumber(i);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

void testTenKAddRange() {
    try {
        Span sp = Span(10001);
        int arr[10001];
        std::srand(std::time(0));
        for (int i = 0; i < 10001; i++)
            arr[i] = std::rand() % 200001 - 100000;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

int main() {
    std::cout << "SUBJECT TEST" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    testSubj();
    std::cout << std::endl;

    std::cout << "EXCEPTIONS TEST" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    testExcepts();
    std::cout << std::endl;

    std::cout << "10k addNumber TEST" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    testTenKAddNumber();
    std::cout << std::endl;

    std::cout << "10k addRange TEST" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    testTenKAddNumber();
    std::cout << std::endl;
}