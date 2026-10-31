#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
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
