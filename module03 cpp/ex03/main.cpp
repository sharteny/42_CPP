#include "DiamondTrap.hpp"

int main()
{
    std::cout << "\n >>> TEST 1 <<<\n";
    DiamondTrap d("Diamond");

    d.attack("enemy");
    d.whoAmI();

    std::cout << "\n >>> TEST 2 <<<\n";

    DiamondTrap tom("Tom");
    DiamondTrap jerry("Jerry");

    tom.attack("Jerry");
    jerry.takeDamage(30);
    tom.beRepaired(40);
    tom.guardGate();   
    tom.highFivesGuys();

    return 0;
}