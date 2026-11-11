#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

RPN::RPN() {}

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
        err = "Error: unsopported operator";
        return false;
    }
}

bool strToInt(const std::string &str, int &num) {
    std::stringstream tmp(str);
    int res;

    if (!(tmp >> res))
        ;
    num = res;
    return true;
}

RPN::RPN(const std::string &arg) {
    std::stringstream ss(arg);
    std::string curr;
    while (ss >> curr) {
        if (isOperator(curr)) {
            if (!data.empty()) {
                int bk = data.back();
                data.pop_back();
                std::string err;
                if (!calc(bk, data.back(), curr, err))
                    throw std::invalid_argument(err);
                data.pop_back();
                data.push_back(bk);
            }
        } else {
            std::stringstream nss(curr);
            int val;
            if (!(nss >> val))
                throw std::invalid_argument("Error: not a valid int.");
            data.push_back(val);
        }
    }
}

RPN::RPN(const RPN &src) {
    *this = src;
}

RPN &RPN::operator=(const RPN &rhs) {
    if (this != &rhs) {
    }
    return (*this);
}

RPN::~RPN() {}
