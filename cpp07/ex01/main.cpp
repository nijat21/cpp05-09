#include "iter.hpp"
#include "Test.hpp"
#include <iostream>
#include <string>

void test_int_arr_const() {
    const int arr[] = {1, 3, 5, 7, 9};
    
    std::cout << "INT" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    iter(arr, 5, printConst<int>);
    std::cout << "---------------------------------------------" << std::endl;
}

void test_int_arr_nonconst() {
    int arr[] = {1, 3, 5, 7, 9};
    
    std::cout << "INT" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    iter(arr, 5, printNonConst<int>);
    std::cout << "---------------------------------------------" << std::endl;
}

void test_str_arr_const() {
    const std::string sarr[] = {"hello", "world", "hello", "life"};

    std::cout << "STRING" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    iter(sarr, 4, printConst<std::string>);
    std::cout << "---------------------------------------------" << std::endl;
}

void test_str_arr_nonconst() {
    std::string sarr[] = {"hello", "world", "hello", "life"};

    std::cout << "STRING" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    iter(sarr, 4, printNonConst<std::string>);
    std::cout << "---------------------------------------------" << std::endl;
}

void test_class_const() {
    const Test people[] = {
        Test("Alice"),
        Test("Bob"),
        Test("Charlie")
    };
    
    std::cout << "CLASS" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    iter(people, 3, printConst<Test>);
    std::cout << std::endl;
}

void test_class_nonconst() {
    Test people[] = {
        Test("Alice"),
        Test("Bob"),
        Test("Charlie")
    };
    
    std::cout << "CLASS" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    iter(people, 3, printNonConst<Test>);
    std::cout << std::endl;
}

int main() {
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "PARSING FUNCTION THAT RECEIVES CONST PARAMETER" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    test_int_arr_const();
    test_str_arr_const();
    test_class_const();

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "PARSING FUNCTION THAT RECEIVES CONST NONPARAMETER" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    test_int_arr_nonconst();
    test_str_arr_nonconst();
    test_class_nonconst();
}

