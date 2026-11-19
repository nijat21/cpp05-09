#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <string>

class RPN {
  public:
    RPN();
    RPN(const std::string &arg);
    RPN(const RPN &src);
    RPN &operator=(const RPN &rhs);
    ~RPN();

    void printResult();
    void printData() const;

  private:
    std::list<int> data;
};

#endif
