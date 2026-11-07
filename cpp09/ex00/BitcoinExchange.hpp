#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
  public:
    BitcoinExchange();
    BitcoinExchange(std::string filename);
    BitcoinExchange(const BitcoinExchange &src);
    BitcoinExchange &operator=(const BitcoinExchange &rhs);
    ~BitcoinExchange();

    void fillData(std::string filename);
    float getRate(std::string date) const;

  private:
    std::map<std::string, float> data;
    std::string dataFile;
};

#endif
