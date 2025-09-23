#include "Zombie.hpp"

int main()
{
    int N = 2;
    Zombie *hord = zombieHorde(N, "HordeZombie");
    int i = 0;

    while (i < N)
    {
        hord[i].announce();
        i++;
    }
    delete[] hord;
    return 0;
}