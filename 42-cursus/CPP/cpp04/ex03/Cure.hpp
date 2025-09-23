#pragma once

#include "AMateria.hpp"


class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &object);
        Cure &operator=(const Cure &object);
        ~Cure();
        AMateria* clone() const;
        void use(ICharacter &target);
};