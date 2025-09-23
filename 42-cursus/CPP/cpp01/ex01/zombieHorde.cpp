#include "Zombie.hpp"


void    Zombie::setName(std::string names)
{
    name = names;
}

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *hord = new Zombie[N];
    int i = 0;

    while (i < N)
    {
        hord[i].setName(name);
        i++;
    }
    return hord;
}
