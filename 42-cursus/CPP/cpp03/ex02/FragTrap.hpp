#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string& Name);
        FragTrap(FragTrap& object);
        FragTrap &operator=(const FragTrap &object);
        ~FragTrap();
        void highFivesGuys(void);
};