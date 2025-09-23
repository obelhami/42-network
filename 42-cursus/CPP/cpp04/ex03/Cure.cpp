#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::Cure(const Cure &object): AMateria(object){}

Cure &Cure::operator=(const Cure &object)
{
    if (this != &object)
        _type = object._type;
    return *this;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void    Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure(){}