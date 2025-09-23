#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "the default constructor of Animal called" << std::endl;
}

Animal::Animal(Animal &object)
{
    std::cout << "the copy constructor of Animal called" << std::endl;
    type = object.type;
}

Animal &Animal::operator=(Animal &object)
{
    if (this != &object)
        type = object.type;
    return *this;
}


std::string Animal::getType() const
{
    return type;
}

Animal::~Animal()
{
    std::cout << "the destructor of Animal called" << std::endl;
}