#include "BitcoinExchange.hpp"
#include "utils.hpp"
#include <fstream>
#include <iostream>

bool posDateEnd(const std::string &str, size_t pos, size_t &newPos) {
    if (pos == std::string::npos || (str.find('|', pos + 1)) != std::string::npos) {
        std::cerr << "Error: bad input => " << str << std::endl;
        return false;
    }
    for (int i = pos; i >= 0; i--) {
        if (std::isdigit(static_cast<unsigned char>(str[i]))) {
            newPos = i;
            return true;
        }
    }
    return false;
}

bool posQtyStart(const std::string &str, size_t pos, size_t &newPos) {
    for (size_t i = pos; i < str.length(); i++) {
        if (str[i] == '-' || str[i] == '+') {
            newPos = i;
            return true;
        }
        if (std::isdigit(static_cast<unsigned char>(str[i]))) {
            newPos = i;
            return true;
        }
    }
    return false;
}

bool validateNum(const std::string &qty, const BitcoinExchange &bt, const std::string &date,
                 float &num) {
    try {
        num = strToFloat(qty) * bt.getRate(date);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return false;
    }
    if (num > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    } else if (num < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    return true;
}

void btc(std::string filename, const BitcoinExchange &bt) {
    std::string line;
    std::ifstream infile(filename.c_str());

    if (!infile.is_open())
        throw std::runtime_error("Couldn't open file: " + filename);
    while (std::getline(infile, line)) {
        if (!std::isalpha(static_cast<unsigned char>(line[0]))) {
            std::size_t pos = line.find('|');
            size_t newPos = 0;
            if (!posDateEnd(line, pos, newPos)) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            const std::string date = line.substr(0, newPos + 1);
            std::string err;
            if (!validDate(date, err)) {
                std::cerr << err << std::endl;
                continue;
            }
            if (!posQtyStart(line, pos, newPos)) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            const std::string qty = line.substr(newPos);
            float num;
            if (!validNumber(qty, err)) {
                std::cerr << err << std::endl;
                continue;
            }
            if (!validateNum(qty, bt, date, num))
                continue;
            std::cout << date << " => " << qty << " = " << num << std::endl;
        }
    }
}
