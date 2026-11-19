#include "utils.hpp"
#include <iostream>
#include <sstream>
#include <string>

bool validNumber(const std::string &str, std::string &err) {
    std::stringstream ss(str);
    int num;
    std::string extra;

    if (!(ss >> num)) {
        if (err.empty())
            err = "Error: not a number: " + str;
        return false;
    }
    if (ss >> extra) {
        if (err.empty())
            err = "Error: number with a trailing char: " + extra;
        return false;
    }
    return true;
}

bool isOperator(const std::string &str, std::string &err) {
    if (str.length() > 1 || !(str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')) {
        if (err.empty())
            err = "Error: not an operator: " + str;
        return false;
    }
    return true;
}

bool calc(int &a, const int &b, const std::string &str, std::string &err) {
    switch (str[0]) {
    case '+':
        a += b;
        return true;
    case '-':
        a = b - a;
        return true;
    case '*':
        a *= b;
        return true;
    case '/':
        a = b / a;
        return true;
    default:
        if (err.empty())
            err = "Error: unsupported operator: " + str;
        return false;
    }
}

int strToInt(const std::string &str) {
    std::stringstream tmp(str);
    int res;

    tmp >> res;
    return res;
}
