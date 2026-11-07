#ifndef UTILS_HPP
#define UTILS_HPP

#include "BitcoinExchange.hpp"
#include <string>

float strToFloat(const std::string &str);
bool validNumber(const std::string &str, std::string& err);
bool validDate(const std::string &str, std::string &err);
bool validRate(const std::string &str, std::string &err);

void btc(std::string filename, const BitcoinExchange &bt);

#endif
