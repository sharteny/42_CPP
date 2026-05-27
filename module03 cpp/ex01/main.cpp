#include "ClapTrap.hpp"

#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("Guardian");
    ScavTrap b("Enemy");

    a.attack("Enemy");
    a.guardGate();

    b.attack("Hero");
    a.takeDamage(15);

    a.attack("Enemy");
    a.beRepaired(10);
    a.guardGate();

    return 0;
}