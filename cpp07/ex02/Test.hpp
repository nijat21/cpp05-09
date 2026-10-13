#ifndef TEST_HPP
# define TEST_HPP

class Test
{
    public:
        Test();
        Test(const Test &src);
        Test &operator=(const Test &rhs);
        ~Test();

    private:
};

#endif
