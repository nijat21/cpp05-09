#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int main() {
    Data d = {"Big", 2};
    Data* dPtr = &d;
    std::cout << "Before --> " << std::endl;
    std::cout << "Name: " << dPtr->name << "; val: " << dPtr->val << std::endl;
   
    uintptr_t ser = Serializer::serialize(dPtr);
    Data* dser = Serializer::deserialize(ser);
    
    std::cout << "After --> " << std::endl;
    std::cout << "Name: " << dser->name << "; val: " << dser->val << std::endl;

    std::cout << "Original: " << dPtr << "\nDeserialized: " << dser << std::endl;
}
