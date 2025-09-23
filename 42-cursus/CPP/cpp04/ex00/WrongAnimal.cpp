#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "the default constructor of WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &object)
{
    std::cout << "the copy constructor of WrongAnimal called" << std::endl;
    type = object.type;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &object)
{
    if (this != &object)
        type = object.type;
    return *this;
}


std::string WrongAnimal::getType() const
{
    return type;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "???" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "the destructor of WrongAnimal called" << std::endl;
}