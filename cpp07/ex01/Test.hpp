#ifndef TEST_HPP
# define TEST_HPP

#include <iostream>
#include <string>

class Test
{
    public:
        Test(const std::string& name);
        ~Test();

        std::string getName() const;

    private:
        const std::string name;
};

std::ostream& operator<<(std::ostream& out, const Test& t);

#endif
