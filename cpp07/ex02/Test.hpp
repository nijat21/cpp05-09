#ifndef TEST_HPP
#define TEST_HPP

#include <string>

class Test {
  public:
    Test();
    Test(std::string &_name);
    Test(const Test &src);
    Test &operator=(const Test &rhs);
    ~Test();

    static int count;
    int getId() const;
    std::string getName() const;

  private:
    int id;
    std::string name;
};

std::ostream &operator<<(std::ostream &os, const Test &t);

#endif
