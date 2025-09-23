#pragma once

#include "Animal.hpp"
#include <iostream>
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(Dog &object);
        Dog &operator=(Dog &object);
        void makeSound() const;
        ~Dog();
};