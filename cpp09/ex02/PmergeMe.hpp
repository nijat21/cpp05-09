#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(std::vector<int> vec);
        PmergeMe(std::deque<int> deq);
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& rhs);
        ~PmergeMe();

        void sortVec();
        // void sortDeq();

    private:
        std::vector<int> vecInp;
        std::deque<int> deqInp;
};

#endif