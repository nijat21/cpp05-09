#include "BitcoinExchange.hpp"
#include <map>
#include <fstream>
#include <string>

BitcoinExchange::BitcoinExchange()
{
    std::string line;
    std::ifstream in("data.csv");
    getline(in, line);    
    while(*line)
}

BitcoinExchange::BitcoinExchange(std::map data) : data(data)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs)
    {
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}
