#include <vector>
#include <string>
#include "utils.hpp"
#include <stdexcept>

std::vector<int> parseVec(char **arr) {
    std::vector<int> vec;
    int i = -1;
    while(arr[++i]) {
        std::string err;
        int dst;
        std::string str;
        try {
            str = arr[i];
        } catch (const std::exception& e) {
            throw e;
        }
        if(!strToInt(str, dst, err))
            throw std::invalid_argument(err);
        vec.push_back(dst);
    }
    return vec;
}


