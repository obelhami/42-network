#pragma once
#include "Weapon.hpp"

class HumanB{
    private:
        std::string name;
        Weapon  *club;
    public:
        HumanB(const std::string& name);
        void    setWeapon(Weapon& newClub);
        void    attack() const;
        ~HumanB();

};