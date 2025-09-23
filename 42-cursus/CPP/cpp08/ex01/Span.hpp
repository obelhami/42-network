#pragma once

#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>

class Span
{
    private:
        unsigned int N;
        std::vector<int> array;
    public:
        Span(unsigned int n);
        Span(const Span& object);
        Span &operator=(const Span& object);
        ~Span();
        void addNumber(const int add);
        template <typename InputIt>
        void addNumber(InputIt begin, InputIt end) {
            while (begin != end) {
                if (array.size() >= N)
                    throw std::runtime_error("Span capacity exceeded");
                array.push_back(*begin);
                ++begin;
            }
        }
        int shortestSpan();
        int longestSpan();
};