#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Cat::Cat()
{
    brain = new Brain;
    std::cout << "The default constructor of the Cat called" << std::endl;
    type = "Cat";
}

Cat::Cat(Cat &object) : Animal(object)
{
    brain = new Brain;
    *this->brain = *object.brain;
}

Cat &Cat::operator=(Cat &object)
{
    if (this != &object)
    {
        Animal::operator=(object);
        brain = new Brain;
        *this->brain = *object.brain;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

Cat::~Cat()
{
    std::cout << "the destructor of the Cat called" << std::endl;
    delete brain;
}