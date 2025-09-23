#pragma once 

#include "ICharacter.hpp"
#include "AMateria.hpp"

class AMateria;

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* Inventory[4];
    public:
        Character(std::string ref);
        Character(const Character &object);
        Character &operator=(const Character &object);
        ~Character();
        std::string const &getName() const;
        void    equip(AMateria* m);
        void    unequip(int idx);
        void    use(int idx, ICharacter& target);
};