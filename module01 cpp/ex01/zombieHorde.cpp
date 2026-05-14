#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
    Zombie *ArrZombie;
    ArrZombie = new Zombie[N];
    for(int i = 0; i < N; i++){
       ArrZombie[i].setname(name);
    }
    return ArrZombie;
}