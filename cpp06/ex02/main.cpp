#include "Base.hpp"
#include <iostream>

void check_same_instance() {
    Base* r = generate();
    Base& ref = *r;
    identify(r);
    identify(ref);
}

void multiple_instances() {
    for(int i = 0; i < 5; i++) {
        Base* r = generate();
        identify(r);
    }
}

int main() {
    check_same_instance();
    multiple_instances();
}


