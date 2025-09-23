#pragma once

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
    public:
        Dog();
        Dog(Dog &object);
        Dog &operator=(Dog &object);
        void makeSound() const;
        ~Dog();
};