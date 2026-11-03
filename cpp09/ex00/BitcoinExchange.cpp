#include "BitcoinExchange.hpp"
#include <map>
#include <fstream>
#include <string>
#include <stdexcept>

BitcoinExchange::BitcoinExchange()
{
    fillData("data.csv");
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
    fillData(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs)
    {
        this->data = rhs.data;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

static validRate(std::string str) {
    if(!str.length()) 
        return false;
    else {
        for(size_t i = 0; i < str.length(); i++) {
            if(isalpha(std::static_cast<int>(str[i])))
               return false; 
        }
    }
    return true;
}

static validRate(std::string str) {
    if(!str.length()) 
        return false;
    else {
        for(size_t i = 0; i < str.length(); i++) {
            if(isalpha(std::static_cast<int>(str[i])))
               return false; 
        }
    }
    return true;
}

// closest earlier date doesn't exist, no values after comma or non-numeric
void BitcoinExchange::fillData(std::string filename) {
    std::string line;
    std::ifstream in(filename);
    std::ofstream out;
    
    dataFile = filename;

    if(!file.isopen()) 
        throw std::runtime_error("Couldn't open file: " + filename);

    while(std::getline(in, line)) {
        if(!std::isalpha(static_cast<unsigned char>(*line))) {
            int pos = line.find(',');
            if(pos != std::string::npos) {
                std::string tmp = line.substr(pos+1);
                if(!validRate(line))
                    throw std::invalid_argument("Invalid data format");
                data[line.substr(0, pos)] = std::static_cast<int>(tmp);
            }
        }
        out << line;
        getline(in, line);    
    }

    if(file.bad())
        throw std::runtime_error("Error reading the file: " + filename)
}

unsigned int BitcoinExchange::getRate(std::string date) {
    return data[date];
}


