#include "Span.hpp"

Span::Span(unsigned int n):N(n)
{
}

Span::Span(const Span& object)
{
    this->N = object.N;
    this->array = object.array;
}
Span &Span::operator=(const Span& object)
{
    if (this != &object)
    {
        this->N = object.N;
        this->array = object.array;
    }
    return *this;
}

Span::~Span()
{
}

void    Span::addNumber(const int add)
{
    if (array.size() < N)
        array.push_back(add);
    else
        throw std::runtime_error("Span capacity exceeded");
}

int  Span::shortestSpan()
{
    if (array.size() < 2) {
        throw std::runtime_error("Not enough elements to compute span.");
    }
    std::vector<int> sortedArray = array;
    std::sort(sortedArray.begin(), sortedArray.end());

    int shortestNum = sortedArray[1] - sortedArray[0];
    for (size_t i = 0; i < sortedArray.size() - 1 ; i++)
    {
        int test = sortedArray[i + 1] - sortedArray[i];
        if (test < shortestNum)
            shortestNum = test;
    }
    return shortestNum;
}

int Span::longestSpan()
{
    if (array.size() < 2) {
        throw std::runtime_error("Not enough elements to compute span.");
    }
    int max = *std::max_element(array.begin(), array.end());
    int min = *std::min_element(array.begin(), array.end());

    return max - min;
}
