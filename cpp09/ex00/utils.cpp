#include "utils.hpp"
#include <iostream>
#include <sstream>
#include <string>

float strToFloat(const std::string &str) {
    std::stringstream tmp(str);
    float res;
    tmp >> res;
    return static_cast<float>(res);
}

bool validNumber(const std::string &str, std::string &err) {
    std::stringstream ss(str);
    float num;
    char extra;

    if (!(ss >> num)) {
        err = "Error: not a number.";
        return false;
    }
    if (ss >> extra) {
        err = "Error: number with a trailing char.";
        return false;
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
        err = "Error: invalid date format.";
    return valid;
}
