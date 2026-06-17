#include "iter.hpp"
#include "Test.hpp"
#include <iostream>
#include <string>

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    std::string sarr[] = {"hello", "world", "hello", "life"};
    Test people[] = {
        Test("Alice"),
        Test("Bob"),
        Test("Charlie")
    };

    std::cout << "Passing function that receive const parameter" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Int" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    iter(arr, 5, printConst<int>);
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "String" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    iter(sarr, 4, printConst<std::string>);
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Class" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    iter(people, 3, printConst<Test>);
    std::cout << std::endl;

    std::cout << "Passing function that receive non-const parameter" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Int" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    iter(arr, 5, printNonConst<int>);
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "String" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    iter(sarr, 4, printNonConst<std::string>);
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Class" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    iter(people, 3, printNonConst<Test>);
}

