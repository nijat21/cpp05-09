#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main(int ac, char* av[])
{
    if(ac > 1) {
        const std::string s(av[1]);
        ScalarConverter::convert(s);
        return 0;
    }

    const std::string tests[] = {
        // Single char inputs
        "a", "*", "f",

        /* // Integers */
        "0", "42", "-42",
        "2147483647", "-2147483648",

        // Floats
        "42.0f", "-42.0f", "0.0f",
        "3.14f", "1000.0f", "-0.001f",
        "3.14", "5.12",

        // Doubles
        "42.0", "-42.0", "0.0",
        "3.14", "1000.0", "-0.001",

        // Pseudo-literals
        "nan", "-nan", "nanf",
        "+inf", "-inf", "inff",
        "+inff", "-inff",

        // Invalid
        "abc", "42abc", "++42", "--42",
        "42..0", ".", "f", "+f",
        "-infabc", "nanabc", "/inf",

        // Boundary / tricky
        "2147483648", "-2147483649",
        "9999999999999999",
        "-9999999999999999",
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        std::cout << "=== Test: " << "'" << tests[i] << "'" << " ===" << std::endl;
        ScalarConverter::convert(tests[i]);
        std::cout << "---------------------------------------------------------" << std::endl;
    }

    return 0;
}
