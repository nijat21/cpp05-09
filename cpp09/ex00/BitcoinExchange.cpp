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

void BitcoinExchange::fillData(std::string filename) {
    std::string line;
    std::ifstream in(filename);
    std::ofstream out;

    if(!file.isopen()) 
        throw std::runtime_error("Couldn't open file: " + filename);

    while(std::getline(in, line)) {
        if(!std::isalpha(static_cast<unsigned char>(*line))) {
            int pos = line.find(',');
            if(pos != std::string::npos)
                data[line.substr(0, pos)] = std::static_cast<int>(line.substr(pos + 1));
        }
        out << line;
        getline(in, line);    
    }

    if(file.bad())
        throw std::runtime_error("Error reading the file: " + filename)
}

unsigned int BitcoinExchange::getPrice(std::string date) {
    return data[date];
}


