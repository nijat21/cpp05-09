#include "easyfind.hpp"
#include <deque>
#include <list>
#include <vector>

int main() {
    std::vector<int> vec;
    std::list<int> lst;
    std::deque<int> dq;

    for (int i = 0; i < 10; i++) {
        vec[i] = i;
        vec.push_back(i);
        lst.push_back(i);
        dq[i] = i;
        dq.push_back(i);
    }
}