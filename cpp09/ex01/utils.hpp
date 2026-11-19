#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

bool validNumber(const std::string &str, std::string &err);
bool isOperator(const std::string &str, std::string &err);
bool calc(int &a, const int &b, const std::string &str, std::string &err);
int strToInt(const std::string &str);

#endif // UTILS_HPP
