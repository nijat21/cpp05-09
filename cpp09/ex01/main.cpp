// #include "RPN.hpp"
// #include <iostream>

// int main(int ac, char **av) {
//     if (ac != 2) {
//         std::cerr << "Program should be run as ./RPN \"1 6 3 25 3\"" << std::endl;
//         return 1;
//     }

//     try {
//         RPN a(av[1]);
//         a.printResult();
//     } catch (const std::exception &e) {
//         std::cerr << e.what() << std::endl;
//     }
// }

#include "RPN.hpp"
#include <iostream>
#include <string>

void runTest(const std::string &label, const std::string &expr, const std::string &expected) {
    std::cout << "[TEST] " << label << "\n"
              << "  Input:    \"" << expr << "\"\n"
              << "  Expected: " << expected << "\n"
              << "  Actual:   ";
    try {
        RPN a(expr);
        a.printResult();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;
}

void runTestSuite(void) {
    std::cout << "=== 42 SUBJECT EXAMPLES ===" << std::endl;
    runTest("Subject 1", "8 9 * 9 - 9 - 9 - 4 - 1 +", "42");
    runTest("Subject 2", "7 7 * 7 -", "42");
    runTest("Subject 3", "1 2 * 2 / 2 * 2 4 - +", "0");
    runTest("Subject 4 (Brackets)", "(1 + 1)", "Error");

    std::cout << "\n=== VALID EDGE CASES ===" << std::endl;
    runTest("Single digit", "5", "5");
    runTest("Zero handling", "0 5 + 0 *", "0");
    runTest("Negative result", "3 9 -", "-6");
    runTest("Multiple spaces", "   8    9   *   ", "72");
    runTest("Tabs and spaces", "4\t2\t/", "2");
    runTest("Sequential operations", "1 2 3 4 + + +", "10");
    runTest("Integer division truncation", "5 2 /", "2");

    std::cout << "\n=== ERROR CASES ===" << std::endl;
    runTest("Empty string", "", "Error");
    runTest("Whitespace only", "    \t  ", "Error");
    runTest("Division by zero", "5 0 /", "Error");
    runTest("Modulo / Unsupported operator", "5 2 %", "Error");
    runTest("Number >= 10 (Subject rule)", "10 2 +", "12");
    runTest("Negative input number", "-5 2 +", "-3");
    runTest("Decimal / Float number", "5.5 2 +", "Error");
    runTest("No spaces between tokens", "89*", "Error");
    runTest("Trailing characters on token", "8 9a *", "Error");
    runTest("Too many operands (leftover on stack)", "8 9 2 *", "Error");
    runTest("Not enough operands (stack underflow)", "8 +", "Error");
    runTest("Operator first", "+ 8 9", "Error");
    runTest("Only an operator", "*", "Error");
    runTest("Invalid letters", "a b +", "Error");
}

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::string arg(av[1]);
    if (arg == "--test") {
        runTestSuite();
        return 0;
    }

    try {
        RPN a(av[1]);
        a.printResult();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}