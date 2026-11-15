#include "utils.hpp"
#include <sstream>
#include <string>

static bool validNumber(const std::string &str, std::string &err) {
    std::stringstream ss(str);
    float num;
    int extra;

    if (!(ss >> num)) {
        err = "Error: not a number.";
        return false;
    }
    if (ss >> extra) {
        err = "Error: number with a trailing char.";
        return false;
    }
    return true;
}

static bool isOperator(std::string str) {
    if (str.length() > 1)
        return false;
    return (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/');
}

static bool calc(int &a, const int &b, const std::string &str, std::string &err) {
    switch (str[0]) {
    case '+':
        a += b;
        return true;
    case '-':
        a -= b;
        return true;
    case '*':
        a *= b;
        return true;
    case '/':
        a /= b;
        return true;
    default:
        err = "Error: unsupported operator.";
        return false;
    }
}

bool strToInt(const std::string &str) {
    std::stringstream tmp(str);
    int res;

    tmp >> res;
    return res;
}
