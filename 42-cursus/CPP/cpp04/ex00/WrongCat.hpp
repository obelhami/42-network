#pragma once

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(WrongCat &object);
        WrongCat &operator=(WrongCat &object);
        void makeSound() const;
        ~WrongCat();
};