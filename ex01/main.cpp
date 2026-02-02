#include <iostream>
#include "Serial.hpp"

int main() {
    Data data;
    data._number = 42;
    data._text = "Hello";

    Data* originalPtr = &data;

    uintptr_t raw = Serializer::serialize(originalPtr);
    std::cout << "Serialized adress value : " << raw << std::endl;

    Data* newPtr = Serializer::deserialize(raw);

    if (newPtr == originalPtr)
        std::cout << "Success! Pointers match." << std::endl;
    else
        std::cout << "Error: pointers do not match." << std::endl;

    std::cout << "originalPtr->number = " << originalPtr->_number << std::endl;
    std::cout << "originalPtr->text = " << originalPtr->_text << std::endl;
    std::cout << "newPtr->number = " << newPtr->_number << std::endl;
    std::cout << "newPtr->text   = " << newPtr->_text << std::endl;

    return 0;
}
