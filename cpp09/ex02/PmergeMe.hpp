#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(std::vector<int> vec);
        PmergeMe(std::deque<int> deq);
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& rhs);
        ~PmergeMe();

    private:
        std::vector<int> vecInp;
        std::deque<int> deqInp;
};

#endif