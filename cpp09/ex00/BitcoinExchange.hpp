#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
  public:
    BitcoinExchange();
    BitcoinExchange(const std::string &filename);
    BitcoinExchange(const BitcoinExchange &src);
    BitcoinExchange &operator=(const BitcoinExchange &rhs);
    ~BitcoinExchange();

    void fillData(const std::string &filename);
    float getRate(const std::string &date) const;

  private:
    std::map<std::string, float> data;
    std::string dataFile;
};

#endif
