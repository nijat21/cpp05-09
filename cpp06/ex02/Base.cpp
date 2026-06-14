#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::Base()
{
}

Base::~Base()
{
}

static Base* createA() {
    return new A();
}

static Base* createB() {
    return new B();
}

static Base* createC() {
    return new C();
}

Base* Base::generate() {
    typedef Base* (*Create)();
    Create creates[3] = {
        createA,
        createB,
        createC
    };
    std::srand(time(0));
    return creates[rand() % 3]();
}

void Base::identify(Base* p) {
    if(dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else 
        std::cerr << "Type not found" << std::endl;
}

void Base::identify(Base& p) {
    bool found = false;
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        found = true;
    } catch(...) {}

    try {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        found = true;
    } catch(...) {}
    
    try {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        found = true;
    } catch(...) {}
    if(!found)
        std::cerr << "Type not found" << std::endl;

}

