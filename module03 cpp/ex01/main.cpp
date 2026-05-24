#include "ClapTrap.hpp"

#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("Guardian");

    a.attack("enemy");

    a.guardGate();

    return 0;
}