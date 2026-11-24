#include <string>
#include <sstream>

std::string* toStr(char** arr) {
    int qty = 0;
    while(arr[qty] != NULL)
        qty++;
    std::string* strArr = new std::string[qty];
    for(int i = 0; i < qty; i++) {
        if(arr[i])
            strArr[i] = arr[i];
    }
    return strArr;
}

bool validNumber(const std::string &str, std::string &err) {
    std::stringstream ss(str);
    int num;
    std::string extra;

    if (!(ss >> num)) {
        if (err.empty())
            err = "Error: not a number: " + str;
        return false;
    }
    if (ss >> extra) {
        if (err.empty())
            err = "Error: number with a trailing char: " + extra;
        return false;
    }
    return true;
}

int strToInt(const std::string &str) {
    std::stringstream tmp(str);
    int res;

    tmp >> res;
    return res;
}

