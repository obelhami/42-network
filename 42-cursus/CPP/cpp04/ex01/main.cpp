#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    int size = 10;
    Animal **animals = new Animal*[size];

    for (int i = 0; i < size / 2; i++)
    {
        animals[i] = new Dog();
        std::cout << animals[i]->getType() << std::endl;
    }

    for (int i = size / 2; i < size; i++)
    {
        animals[i] = new Cat();
        std::cout << animals[i]->getType() << std::endl;
    }

    for (int i = 0; i < size; i++)
    {
       delete animals[i];
    }
    delete[] animals;
    return 0;
}