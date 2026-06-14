#include "Base.hpp"
#include <iostream>

int main() {
    Base a;
    
    Base* r = a.generate();
    Base& ref = *r;
    a.identify(r);
    a.identify(ref);
}

