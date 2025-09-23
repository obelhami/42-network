#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main() 
{
    // std::cout << "\n==== Creating ClapTrap and ScavTrap ====\n";
    // ClapTrap clap("Clappy");
    // ScavTrap scav("Scavvy");

    // std::cout << "\n==== Basic Attacks ====\n";
    // clap.attack("Target A");
    // scav.attack("Target B");

    // std::cout << "\n==== ScavTrap Special Ability ====\n";
    // scav.guardGate();

    // std::cout << "\n==== Taking Damage ====\n";
    // scav.takeDamage(40);

    // std::cout << "\n==== Destroying Objects ====\n";
    FragTrap ob1("omar");
    ob1.highFivesGuys();
    ob1.attack("belhamid");

    ClapTrap ob2("fadila");
    ob2.attack("elboukhari");

    return 0; 
}
