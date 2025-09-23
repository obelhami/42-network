#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(Cat &object);
        Cat &operator=(Cat &object);
        void makeSound() const;
        ~Cat();
};