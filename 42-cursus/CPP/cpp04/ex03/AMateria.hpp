#pragma once

#include <string>
#include <iostream>
#include "ICharacter.hpp"


class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria();
        AMateria(AMateria const &other);
        AMateria(std::string const& type);
        AMateria&operator=(AMateria const &other);
        std::string const &getType() const;
        virtual void    use(ICharacter& target);
        virtual AMateria* clone() const = 0;
        virtual ~AMateria();
};
