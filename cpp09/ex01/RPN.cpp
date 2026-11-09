#include "RPN.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>

RPN::RPN()
{
}

static bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

static bool calc(int& a, const int& b, const int& op, std::string& err) {
    switch(op) {
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

RPN::RPN(const std::string& arg)
{
    std::stringstream ss(arg);
    int curr;
    while(ss >> curr) {
        if(isOperator(curr)) {
            if(!data.empty()) {
                int bk = data.back();
                data.pop_back();
                std::string err;
                if(!calc(bk, data.back(), curr, err))
                    throw std::invalid_argument(err);
                data.pop_back();
                data.push_back(bk);
            }
        } else 
            data.push_back(curr);
    }
}

RPN::RPN(const RPN &src)
{
    *this = src;
}

RPN &RPN::operator=(const RPN &rhs)
{
    if (this != &rhs)
    {
    }
    return (*this);
}

RPN::~RPN()
{
}
