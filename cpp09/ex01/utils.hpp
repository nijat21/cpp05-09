#ifndef UTILS_HPP
#define UTILS_HPP

bool validNumber(const std::string &str, std::string &err);
bool isOperator(std::string str);
bool calc(int &a, const int &b, const std::string &str, std::string &err);
bool strToInt(const std::string &str);

#endif // UTILS_HPP
