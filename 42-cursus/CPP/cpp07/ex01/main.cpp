#include <iostream>
#include <string>
#include "iter.hpp"

// MUST be above main

int main() {
    int intArray[] = {1, 2, 3, 4, 5, 7,4,5,5,32,2,3,5,2,4,23};
    std::cout << "Testing int array:\n";
    ::iter(intArray, (sizeof(intArray) / sizeof(intArray[0])), printElement);

    std::string strArray[] = {"hello", "world", "cpp", "omar"};
    std::cout << "Testing string array:\n";
    ::iter(strArray, strArray->length() - 1, printElement);

    return 0;
}
