#include "Zombie.hpp"

void Zombie::announce( void ){

    std::cout << name <<": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setname(std::string &inputname){
    name = inputname;
}

Zombie::~Zombie()
{
    std::cout << name << " destroyed\n";
}