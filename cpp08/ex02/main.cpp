#include "MutantStack.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <stack>

void testSubj() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "mstack.top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "mstack.size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "mstack traverse" << std::endl;
    while (it != ite) {
        --ite;
        std::cout << *ite << std::endl;
    }
    std::stack<int> s(mstack);
    std::cout << std::endl;

    std::cout << "stack traverse" << std::endl;
    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }
}

void testSubjList() {
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << "list.top: " << list.back() << std::endl;
    list.pop_back();
    std::cout << "list.size: " << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ite = list.end();
    ++it;
    --it;
    std::cout << "mstack traverse" << std::endl;
    while (it != ite) {
        --ite;
        std::cout << *ite << std::endl;
    }
}

void testAddPrintRemove() {
    MutantStack<int> mstack;
    std::srand(std::time(0));
    for (int i = 0; i < 20; i++)
        mstack.push(std::rand() % 200001 - 100000);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator end = mstack.end();
    while (it != end) {
        std::cout << *it << std::endl;
        ++it;
    }
    while (!mstack.empty()) {
        mstack.pop();
    }

    std::cout << (mstack.empty() ? "empty" : "not empty") << std::endl;
}

int main() {
    std::cout << "TEST SUBJ" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    testSubj();
    std::cout << std::endl;

    std::cout << "TEST SUBJ LIST" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    testSubjList();
    std::cout << std::endl;

    std::cout << "TEST ADD PRINT REMOVE" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    testAddPrintRemove();
    std::cout << std::endl;
}