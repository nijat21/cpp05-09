#include "BitcoinExchange.hpp"
#include "utils.hpp"
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Program should be run as ./btc <input.txt>" << std::endl;
        return 1;
    }
    try {
        BitcoinExchange a;
        // std::cout << a.getRate(av[1]) << std::endl;
        std::string filename(av[1]);
        btc(filename, a);

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
