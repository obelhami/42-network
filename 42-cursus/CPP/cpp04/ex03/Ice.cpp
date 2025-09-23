#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice &object): AMateria(object){}

Ice &Ice::operator=(const Ice &object)
{
    if (this != &object)
        _type = object._type;
    return *this;
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void    Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}

Ice::~Ice(){}