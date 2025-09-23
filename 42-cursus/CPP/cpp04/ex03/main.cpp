#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>
#include <string>

// int main()
// {
// IMateriaSource* src = new MateriaSource();
// src->learnMateria(new Ice());
// src->learnMateria(new Cure());
// ICharacter* me = new Character("me");
// AMateria* tmp;
// tmp = src->createMateria("ice");
// me->equip(tmp);
// tmp = src->createMateria("cure");
// me->equip(tmp);
// ICharacter* bob = new Character("bob");
// me->use(0, *bob);
// me->use(1, *bob);
// delete bob;
// delete me;
// delete src;
// return 0;
// }

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
    IMateriaSource* book = new MateriaSource();
    book->learnMateria(new Ice());
    book->learnMateria(new Cure());

    ICharacter* hero = new Character("Hero");

    AMateria* m1 = book->createMateria("ice");
    AMateria* m2 = book->createMateria("cure");
    AMateria* m3 = book->createMateria("ice");
    AMateria* m4 = book->createMateria("cure");
    AMateria* m5 = book->createMateria("ice"); // extra, shouldn't be equipped

    hero->equip(m1);
    hero->equip(m2);
    hero->equip(m3);
    hero->equip(m4);
    hero->equip(m5); // ignored (inventory full)

    ICharacter* npc = new Character("NPC");

    for (int i = 0; i < 4; i++)
        hero->use(i, *npc);

    hero->unequip(1); // unequip Cure
    hero->use(1, *npc); // should do nothing

    // Manual delete for unequipped materia (responsibility of main here)
    delete m5;
    delete m2;

    delete npc;
    delete hero;
    delete book;

    return 0;
}