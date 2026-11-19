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
    std::string err = "";

    while (ss >> curr) {
        if (!isOperator(curr, err) && !validNumber(curr, err))
            throw std::invalid_argument(err);
        if (isOperator(curr, err)) {
            // std::cout << "\nprintData: " << std::endl;
            // printData();
            // std::cout << std::endl;
            if (data.size() < 2)
                throw std::invalid_argument("Error: not enough operands.");
            int bk = data.back();
            // std::cout << "bk0: " << bk << std::endl;
            data.pop_back();
            std::string err;
            if (!calc(bk, data.back(), curr, err))
                throw std::invalid_argument(err);
            data.pop_back();
            data.push_back(bk);
        } else {
            // std::cout << "curr: " << curr << "; int added: " << strToInt(curr) << std::endl;
            data.push_back(strToInt(curr));
        }
    }
    if (data.size() > 1)
        throw std::invalid_argument("Error: not enough operators.");
}

RPN::RPN(const RPN &src) {
    *this = src;
}

RPN &RPN::operator=(const RPN &rhs) {
    if (this != &rhs)
        this->data = rhs.data;
    return (*this);
}

RPN::~RPN() {}

void RPN::printResult() {
    if (data.front() != data.back())
        throw std::runtime_error("Error: front and back differ.");
    std::cout << "Result: " << data.front() << std::endl;
}

void RPN::printData() const {
    for (std::list<int>::const_reverse_iterator it = data.rbegin(); it != data.rend(); it++)
        std::cout << *it << std::endl;
}
