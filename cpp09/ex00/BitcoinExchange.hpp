#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(std::string filename = "data.csv");
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
        ~BitcoinExchange();

        void fillData(std::string filename);
        unsigned int getPrice(std::string date);
    private:
        std::map data;
};

#endif
