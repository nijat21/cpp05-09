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

bool validRate(const std::string &str, std::string &err) {
    if (!str.length()) {
        err = "Error: empty";
        return false;
    } else {
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
    }
    return true;
}

// static bool dateFormat(const std::string &str) {
//     std::string year = str.substr(0, 4);
//     std::string month = str.substr(5, 2);
//     std::string day = str.substr(8);

//     int yr = static_cast<int>(strToFloat(year));
//     if (yr < 1 || yr > 2026)
//         return false;
//     int mt = static_cast<int>(strToFloat(month));
//     if (mt < 1 || mt > 12)
//         return false;
//     int dy = static_cast<int>(strToFloat(day));
//     if (dy < 1 || dy > 31)
//         return false;
//     return true;
// }

bool validDate(const std::string &str, std::string &err) {
    bool valid = true;

    if (str.length() != 10)
        valid = false;
    else if (str[4] != '-' || str[7] != '-')
        valid = false;
    // else if (!dateFormat(str))
    //     valid = false;
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
