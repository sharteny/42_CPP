#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap a("Fraggy");

    a.attack("Enemy");
    a.takeDamage(40);
    a.beRepaired(20);
    a.highFivesGuys();

    return 0;
}