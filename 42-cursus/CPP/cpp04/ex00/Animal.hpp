#pragma once

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(Animal &object);
        Animal &operator=(Animal &object);
        virtual void    makeSound() const;
        std::string getType()const;
        virtual ~Animal();
};