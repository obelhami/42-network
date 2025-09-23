#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "The default constructor of the dog called" << std::endl;
    type = "Dog";
}

Dog::Dog(Dog &object)
{
    type = object.type;
}

Dog &Dog::operator=(Dog &object)
{
    if (this != &object)
        type = object.type;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}

Dog::~Dog()
{
    std::cout << "the destructor of the dog called" << std::endl;
}
