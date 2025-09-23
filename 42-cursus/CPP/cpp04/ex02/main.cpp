#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    // Animal a;
    Dog d;

    std::cout << d.getType() << std::endl;
    d.makeSound();
    return 0;
}