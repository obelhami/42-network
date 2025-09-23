#pragma once

#include <iostream>

class   Zombie{
    private:
        std::string name;
    public:
        Zombie();
        void    setName(std::string names);
        void    announce();
        ~Zombie();
};

Zombie* zombieHorde( int N, std::string name);