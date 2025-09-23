#pragma once
#include <iostream>
#include <cstddef> // For size_t

template <typename T>
void printElement(const T& element) {
            std::cout << element << std::endl;
}

template <typename T>
void iter(T* array, size_t length, void (*func)(T const&)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

