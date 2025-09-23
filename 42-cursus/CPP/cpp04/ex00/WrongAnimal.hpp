#pragma once

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal &object);
        WrongAnimal &operator=(WrongAnimal &object);
        void    makeSound() const;
        std::string getType()const;
        ~WrongAnimal();
};