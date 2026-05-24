#include "ClapTrap.hpp"


ClapTrap::ClapTrap(const std::string &name){
    this->name = name;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout << "ClapTrap " << this->name << " created!" << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if(hit_points <= 0){
        std::cout << name << " is dead and can't attack!" << std::endl;
        return;
    }
    if(energy_points <=0){
        std::cout << name << " has no energy points left!" << std::endl;
        return;
    }
    energy_points--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount){
    if(hit_points <= 0){
        std::cout << name << " is already dead!" << std::endl;
        return;
    }
    hit_points -= amount;
    if(hit_points < 0)
        hit_points = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " damage!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount){
    if(hit_points <= 0){
        std::cout << name << " is dead and can't repair itself!" << std::endl;
        return;
    }
    if(energy_points <= 0){
        std::cout << name << " has no energy points left!" << std::endl;
        return;
    }
    energy_points--;
    hit_points +=amount;
     std::cout << "ClapTrap " << name << " repaired itself for " << amount << " hit points!" << std::endl;
}