#include "utils.hpp"
#include <iostream>
#include <sstream>
#include <string>

float strToFloat(const std::string &str) {
    std::istringstream tmp(str);
    float res;
    tmp >> res;
    return static_cast<float>(res);
}

bool validNumber(const std::string &str, std::string& err) {
    size_t i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i]) {
        if (isalpha(static_cast<unsigned char>(str[i]))) {
            err = "Error: not a number.";
            return false;
        }
        i++;
    }
    if (strToFloat(str) < 0) {
        err = "Error: not a positive number.";
        return false;
    }
    return true;
}

bool validRate(const std::string &str, std::string &err) {
    if (!str.length()) {
        err = "Error: empty";
        return false;
    } else 
        validNumber(str, err);
    return true;
}

bool validDate(const std::string &str, std::string &err) {
    bool valid = true;

    if (str.length() != 10)
        valid = false;
    else if (str[4] != '-' || str[7] != '-')
        valid = false;
    else
        for (size_t i = 0; i < str.length(); i++) {
            if (i == 4 || i == 7)
                continue;
            if (!std::isdigit(str[i])) {
                valid = false;
                break;
            }
        }
    if (!valid)
        err = "Invalid date format.";
    return valid;
}
