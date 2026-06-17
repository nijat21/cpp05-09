#include "Test.hpp"
#include <string>
#include <iostream>

Test::Test(const std::string& name) : name(name) {}

Test::~Test()
{
}

std::string Test::getName() const {
    return name;
}

std::ostream& operator<<(std::ostream& out, const Test& t) {
    out << t.getName();
    return out;
}

