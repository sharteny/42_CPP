#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name):ClapTrap(name){
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;

    std::cout << "FragTrap " << this->name << " created!" << std::endl;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap " << name << " destroyed!" << std::endl;
}

void FragTrap::highFivesGuys(void){
     std::cout << "FragTrap " << name << " requests high fives!" << std::endl;
}

