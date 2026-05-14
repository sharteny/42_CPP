#include "Zombie.hpp"

int main(){
    Zombie *Zombie1 = zombieHorde(6, "Name");
    Zombie1[0].announce();
    Zombie1[1].announce();
    Zombie1[2].announce();
    Zombie1[3].announce();
    Zombie1[4].announce();
    Zombie1[5].announce();
    delete[] Zombie1;
}