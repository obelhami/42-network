#include "Zombie.hpp"

int main()
{
    Zombie *heap = newZombie("omar belhamid heap");
    heap->announce();
    delete heap;
    randomChump("omar belhamid stack");
    return 0;
}