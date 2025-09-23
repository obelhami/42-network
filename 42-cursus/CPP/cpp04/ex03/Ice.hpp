#pragma once

#include "AMateria.hpp"


class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice &object);
        Ice &operator=(const Ice &object);
        ~Ice();
        AMateria* clone() const;
        void use(ICharacter &target);
};