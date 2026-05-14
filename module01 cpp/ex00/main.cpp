#include "Zombie.hpp"

int main(){
    Zombie *Zombie1 = newZombie("FOO");
    Zombie1->announce();
    randomChump("Name");
    delete Zombie1;
}