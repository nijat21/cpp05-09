#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename T>
void test_valid(const T &cont, std::string var_name) {
    try {
        std::cout << "easyfind(" << var_name << ", 5) --> ";
        std::cout << *(easyfind(cont, 5)) << std::endl;
        std::cout << "easyfind(" << var_name << ", 0) --> ";
        std::cout << *(easyfind(cont, 0)) << std::endl;
        std::cout << "easyfind(" << var_name << ", 9) --> ";
        std::cout << *(easyfind(cont, 9)) << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

template <typename T>
void test_invalid(const T &cont, std::string var_name) {
    try {
        std::cout << "easyfind(" << var_name << ", 10) --> " << *(easyfind(cont, 10)) << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "easyfind(" << var_name << ", -1) --> " << *(easyfind(cont, -1)) << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "easyfind(" << var_name << ", 500) --> " << *(easyfind(cont, 500))
                  << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    std::vector<int> vec;
    std::vector<int> vec1(10);
    std::list<int> lst;
    std::deque<int> dq;
    std::deque<int> dq1(10);

    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
        vec1[i] = i; // -> if using [i] for assignment, size should be predefined
        lst.push_back(i);
        dq.push_back(i);
        dq1[i] = i; // -> if using [i] for assignment, size should be predefined
    }

    std::cout << "VALID CASES" << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "VECTORS" << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    test_valid(vec, "vec");
    test_valid(vec1, "vec1");
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "LIST" << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    test_valid(lst, "lst");
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "DEQUES" << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    test_valid(dq, "dq");
    test_valid(dq1, "dq1");
    std::cout << "-----------------------------------------------------------" << std::endl;

    std::cout << "\n" << std::endl;
    std::cout << "INVALID CASES" << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "VECTORS" << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    test_invalid(vec, "vec");
    test_invalid(vec1, "vec1");
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "LIST" << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    test_invalid(lst, "lst");
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "DEQUES" << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;
    test_invalid(dq, "dq");
    test_invalid(dq1, "dq1");
    std::cout << "-----------------------------------------------------------" << std::endl;
}