#include "PmergeMe.hpp"
#include <vector>
#include <deque>

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(std::vector<int> vec){
    vecInp = vec;
}

PmergeMe::PmergeMe(std::deque<int> deq){
    deqInp = deq;
}

PmergeMe::PmergeMe(const PmergeMe& src){
    *this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs){
    if(this != &rhs)
    {
        vecInp = rhs.vecInp;
        deqInp = rhs.deqInp;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}

void PmergeMe::sortVec() {
    // Divide into two vectors comparing adjacent numbers
    // Sort b vector keeping the related a's for each b
    // Insert the first a
        // ... 
    
}

