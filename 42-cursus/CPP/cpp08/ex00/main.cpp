#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
    std::list<int> container;
    container.push_back(52);
    container.push_back(51);
    container.push_back(556);
    container.push_back(522);
    container.push_back(345);
    container.push_back(34);
    container.push_back(3);
    try
    {
        std::list<int>::iterator omar = easyfind(container, 66);
        std::cout << *omar << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}