#include "BitcoinExchange.hpp"
#include "utils.hpp"
#include <fstream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

BitcoinExchange::BitcoinExchange() {
    fillData("data.csv");
}

BitcoinExchange::BitcoinExchange(const std::string &filename) {
    fillData(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
    if (this != &rhs) {
        this->data = rhs.data;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::fillData(const std::string &filename) {
    std::string line;
    std::ifstream infile(filename.c_str());
    std::string err;

    if (!infile.is_open())
        throw std::runtime_error("Error: couldn't open file: " + filename);

    while (std::getline(infile, line)) {
        if (!std::isalpha(static_cast<unsigned char>(line[0]))) {
            size_t pos = line.find(',');
            std::string date;
            std::string rate;
            if ((pos == std::string::npos) || (line.find(',', pos + 1) != std::string::npos) ||
                !validDate(date = line.substr(0, pos), err) ||
                !validRate(rate = line.substr(pos + 1), err))
                throw std::invalid_argument(err);
            int tmpNum;
            if (!strToFloat(rate, tmpNum))
                throw std::invalid_argument("Error: not a number.");
            data[date] = tmpNum;
        }
    }
    if (infile.bad())
        throw std::runtime_error("Error: couldn't read the file: " + filename);
}

float BitcoinExchange::getRate(const std::string &date) const {
    std::string err;
    if (!validDate(date, err))
        throw std::invalid_argument(err);

    std::map<std::string, float>::const_iterator it = data.upper_bound(date);
    if (it == data.begin() || it == data.end())
        throw std::invalid_argument("Error: invalid date.");
    else
        return (--it)->second;
}
