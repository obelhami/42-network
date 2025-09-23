#include "Character.hpp"

Character::Character(std::string ref) : name(ref)
{
    for (int i = 0; i < 4; i++)
    {
        Inventory[i] = NULL;
    }
}

Character::Character(const Character &object)
{
    *this = object; 
}

Character &Character::operator=(const Character &object)
{
    this->name = object.name;
    for(int i = 0; i < 4; i++)
    {
        if (object.Inventory[i])
            this->Inventory[i] = object.Inventory[i]->clone();
        else
            this->Inventory[i] = NULL;
    }
    return *this;
}

std::string const &Character::getName() const
{
    return name;
}

void    Character::equip(AMateria* m)
{
    if (m == NULL)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!Inventory[i])
        {
            Inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{

        if (Inventory[idx])
            Inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (Inventory[idx])
    {
        Inventory[idx]->use(target);
    }
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (Inventory[i])
        {
            delete Inventory[i];
            Inventory[i] = NULL;
        }
    }
}