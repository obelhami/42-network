#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;

    std::cout << "-------------------------------------\n";

        const WrongAnimal* metax = new WrongAnimal();
    const WrongAnimal* ix = new WrongCat();
    std::cout << ix->getType() << " " << std::endl;
    ix->makeSound(); //will output the cat sound!
    metax->makeSound();
    delete metax;
    delete ix;

return 0;
}