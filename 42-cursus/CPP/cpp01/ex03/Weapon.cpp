#include "Weapon.hpp"

Weapon::Weapon(const std::string& type): type(type){}


const std::string& Weapon::getType() const
{
    return type;
}

void    Weapon::setType(std::string club)
{
    this->type = club;
}

Weapon::~Weapon(){}