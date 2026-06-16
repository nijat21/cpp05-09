#include "Test.hpp"

Test::Test()
{
}

Test::Test(const Test &src)
{
    *this = src;
}

Test &Test::operator=(const Test &rhs)
{
    if (this != &rhs)
    {
    }
    return (*this);
}

Test::~Test()
{
}
