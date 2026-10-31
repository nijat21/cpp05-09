#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &src)
{
    *this = src;
}

RPN &RPN::operator=(const RPN &rhs)
{
    if (this != &rhs)
    {
    }
    return (*this);
}

RPN::~RPN()
{
}
