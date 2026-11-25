#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

//---------utils.cpp----------------------------------------------
std::string* toStr(char** arr);
bool strToInt(const std::string &str, int& dst, std::string &err);

//---------parseVec.cpp----------------------------------------------
std::vector<int> parseVec(char **arr);

#endif