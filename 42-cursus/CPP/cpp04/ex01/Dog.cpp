#include "Dog.hpp"

Dog::Dog()
{
    brain = new Brain;
    std::cout << "The default constructor of the dog called" << std::endl;
    type = "Dog";
}

Dog::Dog(Dog &object) : Animal(object)
{
    brain = new Brain;
    *this->brain = *object.brain;
}

Dog &Dog::operator=(Dog &object)
{
    if (this != &object)
    {
        Animal::operator=(object);
        brain = new Brain;
        *this->brain = *object.brain;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}

Dog::~Dog()
{
    std::cout << "the destructor of the dog called" << std::endl;
    delete brain;
}
