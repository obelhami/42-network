#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :HitPoints(10), EnegryPoints(10), AttackDamage(0)
{
    std::cout << "the default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& Name): name(Name),HitPoints(10), EnegryPoints(10), AttackDamage(0)
{
    std::cout << "the parametrized constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& object)
{
    std::cout << "the copy constructor called" << std::endl;
    *this = object;
}

ClapTrap    &ClapTrap::operator=(const ClapTrap &object)
{
    std::cout << "the copy assignment called" << std::endl;
    if (this == &object)
        return *this;
    name = object.name;
    HitPoints = object.HitPoints;
    EnegryPoints = object.EnegryPoints;
    AttackDamage = object.AttackDamage;
    return *this;
}
void    ClapTrap::attack(const std::string& target)
{
    if (EnegryPoints > 0 && HitPoints > 0)
    {
        std::cout << "ClapTrap " << name <<  " attacks "<< target <<" , causing " << AttackDamage << " points of damage!" << std::endl;
        EnegryPoints -= 1;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (EnegryPoints > 0 && HitPoints > 0)
    {
        std::cout << "ClapTrap " << name <<  " repairs itself it gets " << amount << " hit points back" << std::endl;
        HitPoints += amount;
        EnegryPoints -= 1; 
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (HitPoints > 0)
    {
        std::cout << "ClapTrap " << name << " take a dammage of " << amount << std::endl;
        HitPoints -= amount;
        if (HitPoints < 0)
            HitPoints = 0;
    }
}

ClapTrap::~ClapTrap()
{
    std::cout << "the destructor called" << std::endl;
}
