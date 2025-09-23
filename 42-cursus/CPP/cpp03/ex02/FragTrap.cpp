#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <ostream>

FragTrap::FragTrap()
{
    std::cout << "FragTrap " << name << " has been constructed!" << std::endl;
    HitPoints = 100;
    EnegryPoints = 100;
    AttackDamage = 30;
}

FragTrap::FragTrap(const std::string& Name) : ClapTrap(Name)
{
    std::cout << "FragTrap " << name << " has been constructed!" << std::endl;
    name = Name;
    HitPoints = 100;
    EnegryPoints = 100;
    AttackDamage = 30;
}

FragTrap::FragTrap(FragTrap& object)
{
    std::cout << "the copy constructor of derived called" << std::endl;
    *this = object;
}

FragTrap    &FragTrap::operator=(const FragTrap &object)
{
    std::cout << "the copy assignment of derived called" << std::endl;
    if (this == &object)
        return *this;
    name = object.name;
    HitPoints = object.HitPoints;
    EnegryPoints = object.EnegryPoints;
    AttackDamage = object.AttackDamage;
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FlagTrap " << name << " wanna do a high fives!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " has been destroyed!" << std::endl;
}