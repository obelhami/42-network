#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &club): name(name), club(club){}

void HumanA::attack() const
{
    std::cout << name << " attacks with their " << club.getType() << std::endl;
}

HumanA::~HumanA(){}