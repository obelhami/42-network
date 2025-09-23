#include "HumanB.hpp"
#include <string>

HumanB::HumanB(const std::string& name): name(name), club(NULL){}

void HumanB::attack() const
{
    if (club) 
    {
        std::cout << name << " attacks with their " << club->getType() << std::endl;
    } else 
    {
        std::cout << name << " has no weapon to attack with" << std::endl;
    }
}

void    HumanB::setWeapon(Weapon& newClub)
{
    club = &newClub;
}

HumanB::~HumanB(){}