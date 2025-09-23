#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "The default constructor of the WrongCat called" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &object)
{
    type = object.type;
}

WrongCat &WrongCat::operator=(WrongCat &object)
{
    if (this != &object)
        type = object.type;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "the destructor of the WrongCat called" << std::endl;
}
