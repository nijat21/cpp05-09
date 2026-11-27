#include "PmergeMe.hpp"
#include <deque>
#include <vector>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> vec) {
    vecInp = vec;
}

PmergeMe::PmergeMe(std::deque<int> deq) {
    deqInp = deq;
}

PmergeMe::PmergeMe(const PmergeMe &src) {
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
    if (this != &rhs) {
        vecInp = rhs.vecInp;
        deqInp = rhs.deqInp;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void insertVec() {}

/*
    - Pair into large and small
    - Sort large list
    - Insert backwards with Jacobshtal
*/

bool vecSorted(const std::vector<int>& vec) {
    for(int i = 0; i < vec.size() - 1; i++) {
        if(vec[i] > vec[i + 1])
            return false;
    }
    return true;
}

void recSort(std::vector<int> &lg, std::vector<int> &sm, int i) {
    if(i + 1 < lg.size()) {
        if(lg[i] > lg[i+1]) {
            std::swap(lg[i], lg[i+1]);
            std::swap(sm[i], sm[i+1]);
        } 
    } 
    if(!vecSorted(lg)) {
        if(i+1 >= lg.size())
            recSort(lg, sm, 0);
        else  
            recSort(lg, sm, i+1);
    } else
        return;
}

void pairVec(const std::vector<int> &vec, std::vector<int> &sm, std::vector<int> &lg) {
    for (int i = 0; i < vec.size() - 1; i++) {
        sm.push_back((vec[i] < vec[i + 1]) ? vec[i] : vec[i + 1]);
        lg.push_back((vec[i] > vec[i + 1]) ? vec[i] : vec[i + 1]);
    }
    if(lg.size() > 2)
        pairVec()
    // recSort();
    if (vec.size() % 2) {
        ; // odd leftover binary search and insert at the end
    }
}

void PmergeMe::sortVec() {
    /*
     * Pairing function: Takes the input vector and creates smaller and larger vectors (plus handles an odd leftover element).
     * Recursive sorting function: Recursively sorts the larger elements while preserving their association with the smaller elements.
     * Insertion function: Inserts the pending smaller elements into the sorted main chain using binary search and Jacobsthal ordering.
*/
    if (vecInp.size() <= 1)
        return;
    if (vecInp.size() == 2) {
        if (vecInp[0] > vecInp[1])
            std::swap(vecInp[0], vecInp[1]);
        return;
    }
    std::vector<int> sm;
    std::vector<int> lg;
    // recSort();
}
