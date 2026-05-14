#include "Zombie.hpp"

void Zombie::announce( void ){

    std::cout << name <<": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string &inputname)
{
    name = inputname;
}

Zombie::~Zombie()
{
    std::cout << name << " destroyed\n";
}