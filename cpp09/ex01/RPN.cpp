#include "RPN.hpp"
#include "utils.hpp"
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <string>

RPN::RPN() {}

RPN::RPN(const std::string &arg) {
    std::stringstream ss(arg);
    std::string curr;
    std::string err;
    while (ss >> curr) {
        if (!isOperator(curr) && !validNumber(curr, err))
            throw std::invalid_argument("Error: invalid syntax.");
        if (isOperator(curr)) {
            if (data.empty() || data.size() < 2)
                throw std::invalid_argument("Error: not enough operands.");
            int bk = data.back();
            data.pop_back();
            std::string err;
            if (!calc(bk, data.back(), curr, err))
                throw std::invalid_argument(err);
            data.pop_back();
            data.push_back(bk);
        } else
            data.push_back(strToInt(curr));
    }
    std::cout << "Result: " << data.front() << std::endl;
}

RPN::RPN(const RPN &src) {
    *this = src;
}

RPN &RPN::operator=(const RPN &rhs) {
    if (this != &rhs) {
        for (std::list<int>::const_iterator it = rhs.data.begin(); it != rhs.data.end(); ++it) {
            this->data.push_back(*it);
        }
    }
    return (*this);
}

RPN::~RPN() {}
