#pragma once

#include <iostream>

class ClapTrap
{
    private:
        std::string name;
        int HitPoints;
        int EnegryPoints;
        int AttackDamage;
    public:
        ClapTrap();
        ClapTrap(const std::string& Name);
        ClapTrap(ClapTrap& object);
        ClapTrap &operator=(const ClapTrap &object);
        ~ClapTrap();
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};