#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

float strToFloat(const std::string &str);
bool validDate(const std::string &str, std::string &err);
bool validRate(const std::string &str, std::string &err);

#endif
