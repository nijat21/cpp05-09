#include "Test.hpp"
#include <iostream>
#include <string>

int Test::count = 0;

Test::Test() : id(count), name("default") {
    count++;
}

Test::Test(std::string &_name) : id(count), name(_name) {
    count++;
}

Test::Test(const Test &src) {
    *this = src;
}

Test &Test::operator=(const Test &rhs) {
    if (this != &rhs) {
        id = rhs.id;
    }
    return (*this);
}

Test::~Test() {}

int Test::getId() const {
    return id;
}

std::string Test::getName() const {
    return name;
}

std::ostream &operator<<(std::ostream &os, const Test &t) {
    os << "Test " << t.getId() << ": " << t.getName() << "\n";
    return os;
}
