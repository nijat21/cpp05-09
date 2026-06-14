#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <limits>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
    if (this != &rhs)
    {
    }
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

static void printChar(const double num, const bool pseudo) {
    std::cout << "char: ";
    if(pseudo || (num > std::numeric_limits<char>::max()) || (num < std::numeric_limits<char>::min())) {
        std::cout << "impossible" << std::endl;
        return;
    } 
    char c = static_cast<char>(num);
    if(c < 32 || c > 126)
        std::cout << "not printable";
    else
        std::cout << "'" << c << "'";
    std::cout << std::endl;
}

static void printInt(const double num, const bool pseudo) {
    std::cout << "int: ";
    if(pseudo || (num > std::numeric_limits<int>::max()) || (num < std::numeric_limits<int>::min())){
        std::cout << "impossible" << std::endl;
    } else 
        std::cout << static_cast<int>(num) << std::endl;
}

static void printFloatDouble(const double num) {
    int inLimit = true;
    if(num > std::numeric_limits<float>::max() || num < -std::numeric_limits<float>::max()) {
        inLimit = false;
    }
    float f = static_cast<float>(num);
    bool fraction = (num != static_cast<int>(num)); 
    std::cout << "float: ";
    if(inLimit)
        std::cout << f << (fraction ? "f" : ".0f");
    else 
        std::cout << "impossible";
    std::cout << std::endl;
    std::cout << "double: " << num << (fraction ?  "" : ".0") << std::endl;
}

/*
 *              num=0;      end='';
 *              num=42;     end='f' 
 *              num=0;      end='c'
 *  str='';     num=0;      end='f'  -> input: f 
 *  str=0;      num=0;      end='f'  -> input: 0f 
 *              num=nan;    end='f'
 *              num=42;     end='f'
 *              num=0;      end='ab'
 *              num=42;     end='ab'
*/
void ScalarConverter::convert(const std::string& str) {
    char* end;
    double num = strtod(str.c_str(), &end);
    bool pseudo = false;
    if(isnan(num) || isinf(num))
        pseudo = true;
    if(*end) {
        int len = strlen(end);
        if(len > 1) {
            std::cerr << "Invalid input" << std::endl;
            return;
        } 
        if(len == 1 && num == 0 && str.length() == 1)
            num = static_cast<double>(*end); 
    }
    printChar(num, pseudo);   
    printInt(num, pseudo);
    printFloatDouble(num);
}

