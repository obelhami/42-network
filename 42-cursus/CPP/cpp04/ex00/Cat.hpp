#pragma once

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
    public:
        Cat();
        Cat(Cat &object);
        Cat &operator=(Cat &object);
        void makeSound() const;
        ~Cat();
};