#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie{
    private:
        std::string name;
        int N;
    public:
        void announce( void );
        void setname(std::string &inputname);
        ~Zombie();
};
 
Zombie* zombieHorde( int N, std::string name );

#endif