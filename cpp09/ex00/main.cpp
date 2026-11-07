#include "BitcoinExchange.hpp"
#include "utils.hpp"
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

void btc(std::string filename, const BitcoinExchange &bt) {
    std::string line;
    std::ifstream infile(filename);

    if (!infile.is_open())
        throw std::runtime_error("Couldn't open file: " + filename);

    while (std::getline(infile, line)) {
        if (!std::isalpha(static_cast<unsigned char>(line[0]))) {
            std::size_t pos = line.find('|');
            if (pos == std::string::npos || (line.find('|', pos + 1)) != std::string::npos ||
                !line[pos + 1] || !line[pos + 2]) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            const std::string date = line.substr(0, pos - 1);
            std::string err;
            if (!validDate(date, err)) {
                std::cerr << err << std::endl;
                continue;
            }
            const std::string qty = line.substr(pos + 2);
            if (!qty.length()) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            if (!validRate(qty, err)) {
                std::cerr << err << std::endl;
                continue;
            }
            float num = strToFloat(qty);
            num *= bt.getRate(date);
            if (num > 1000) {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            } else if (num < 0) {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            std::cout << date << " => " << qty << " = " << num << std::endl;
        }
    }
}

int main(int ac, char **av) {
    (void)ac;
    (void)av;
    // if (ac < 2) {
    //     std::cerr << "Program should be run as ./btc <input.txt>" << std::endl;
    //     return 1;
    // }
    try {
        BitcoinExchange a;
        // std::cout << a.getRate(av[1]) << std::endl;

        btc("input.txt", a);

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
