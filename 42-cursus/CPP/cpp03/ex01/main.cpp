#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main() 
{
    std::cout << "\n==== Creating ClapTrap and ScavTrap ====\n";
    ClapTrap clap("Clappy");
    ScavTrap scav("scavy");

    std::cout << "\n==== Basic Attacks ====\n";
    clap.attack("Target A");
    scav.attack("Target B");

    std::cout << "\n==== ScavTrap Special Ability ====\n";
    scav.guardGate();

    std::cout << "\n==== Taking Damage ====\n";
    scav.takeDamage(40);

    std::cout << "\n==== Destroying Objects ====\n";
    return 0; 
}
