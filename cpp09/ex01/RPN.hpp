#ifndef RPN_HPP
# define RPN_HPP

#include <list>
#include <string>

class RPN
{
    public:
        RPN();
        RPN(const std::string &src);
        RPN(const RPN &src);
        RPN &operator=(const RPN &rhs);
        ~RPN();

    private:
        std::list<int> data;
};

#endif
