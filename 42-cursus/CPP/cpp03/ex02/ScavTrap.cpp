#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap " << name << " has been constructed!" << std::endl;
    HitPoints = 100;
    EnegryPoints = 50;
    AttackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& Name) : ClapTrap(Name)
{
    std::cout << "ScavTrap " << name << " has been constructed!" << std::endl;
    name = Name;
    HitPoints = 100;
    EnegryPoints = 50;
    AttackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap& object)
{
    std::cout << "the copy constructor of derived called" << std::endl;
    *this = object;
}

ScavTrap    &ScavTrap::operator=(const ScavTrap &object)
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

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is " << name << "  is now in Gate keeper mode "<< std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " has been destroyed!" << std::endl;
}