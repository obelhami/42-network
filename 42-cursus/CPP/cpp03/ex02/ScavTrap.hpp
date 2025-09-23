#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const std::string& Name);
        ScavTrap(ScavTrap& object);
        ScavTrap &operator=(const ScavTrap &object);
        ~ScavTrap();
        void guardGate();
};