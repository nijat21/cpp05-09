#include "BitcoinExchange.hpp"
#include "utils.hpp"
#include <iostream>
#include <fstream>

bool posDateEnd(const std::string& str, size_t pos, size_t& newPos) {
    for(int i = pos - 1; i >= 0; i--) {
        if(std::isdigit(static_cast<unsigned char>(str[i]))) {
            newPos = i;
            return true;
        } 
    }
    return false;
}

bool posQtyStart(const std::string& str, size_t pos, size_t& newPos) {
    for(size_t i = pos; i < str.length(); i++) {
        if(std::isdigit(static_cast<unsigned char>(str[i]))) {
            newPos = i;
            return true;
        } 
    }
    return false;
}

void btc(std::string filename, const BitcoinExchange &bt) {
    std::string line;
    std::ifstream infile(filename.c_str());

    if (!infile.is_open())
        throw std::runtime_error("Couldn't open file: " + filename);

    while (std::getline(infile, line)) {
        if (!std::isalpha(static_cast<unsigned char>(line[0]))) {
            std::size_t pos = line.find('|');
            if (pos == std::string::npos || (line.find('|', pos + 1)) != std::string::npos ||
                !line[pos + 1] || !line[pos + 2]) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            size_t newPos = 0;
            if(!posDateEnd(line, pos, newPos)) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            const std::string date = line.substr(0, newPos + 1);
            std::string err;
            if (!validDate(date, err)) {
                std::cerr << err << std::endl;
                continue;
            }
            if(!posQtyStart(line, pos, newPos)) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            const std::string qty = line.substr(newPos);
            if (!validNumber(qty, err)) {
                std::cerr << err << std::endl;
                continue;
            }
            float num = strToFloat(qty);
            num *= bt.getRate(date);
            if (num > 1000) {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            } else if (num < 0) {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            std::cout << date << " => " << qty << " = " << num << std::endl;
        }
    }
}