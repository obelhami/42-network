#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
        {
            Weapon club = Weapon("crude spiked club");
            HumanA bob("Bob", club);
            bob.attack();
            club.setType("some other type of club");
            bob.attack();
        }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.attack();
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
}

// #include <iostream>
// #include "Weapon.hpp"
// #include "HumanA.hpp"
// #include "HumanB.hpp"

// int main() {
//     {
//         std::cout << "===== Test 1: HumanA =====" << std::endl;
//         Weapon club = Weapon("crude spiked club");
//         HumanA bob("Bob", club);
//         bob.attack(); // Bob attacks with their crude spiked club

//         club.setType("some other type of club");
//         bob.attack(); // Bob attacks with their some other type of club
//         std::cout << std::endl;
//     }

//     {
//         std::cout << "===== Test 2: HumanB =====" << std::endl;
//         Weapon club = Weapon("crude spiked club");
//         HumanB jim("Jim");

//         jim.attack(); // Jim has no weapon to attack with

//         jim.setWeapon(club);
//         jim.attack(); // Jim attacks with their crude spiked club

//         club.setType("some other type of club");
//         jim.attack(); // Jim attacks with their some other type of club
//         std::cout << std::endl;
//     }

//     {
//         std::cout << "===== Test 3: HumanB (No Weapon) =====" << std::endl;
//         HumanB tim("Tim");

//         tim.attack(); // Tim has no weapon to attack with
//         tim.attack(); // Tim has no weapon to attack with
//         std::cout << std::endl;
//     }

//     {
//         std::cout << "===== Test 4: Shared Weapon =====" << std::endl;
//         Weapon sword = Weapon("sword");

//         HumanA alice("Alice", sword);
//         HumanB bob("Bob");

//         alice.attack(); // Alice attacks with their sword
//         bob.attack();   // Bob has no weapon to attack with

//         bob.setWeapon(sword);
//         bob.attack(); // Bob attacks with their sword

//         sword.setType("katana");
//         alice.attack(); // Alice attacks with their katana
//         bob.attack();   // Bob attacks with their katana
//         std::cout << std::endl;
//     }

//     return 0;
// }