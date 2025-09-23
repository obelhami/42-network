#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "The default constructor of the Cat called" << std::endl;
    type = "Cat";
}

Cat::Cat(Cat &object)
{
    type = object.type;
}

Cat &Cat::operator=(Cat &object)
{
    if (this != &object)
        type = object.type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

Cat::~Cat()
{
    std::cout << "the destructor of the Cat called" << std::endl;
}
