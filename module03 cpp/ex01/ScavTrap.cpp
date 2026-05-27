#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap Default constructor called";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap Copy constructor called for " << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap Copy assignment operator called " << std::endl;

    return (*this);
}


ScavTrap::ScavTrap(const std::string &name):ClapTrap(name){
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap " << this->name << " created!" << std::endl;
}

void ScavTrap::attack(const std::string& target){
    if(hit_points <=0){
        std::cout << "ScavTrap " << name << " is dead!" << std::endl;
        return;
    }
    if(energy_points <=0){
         std::cout << "ScavTrap " << name << " has no energy!" << std::endl;
        return;
    }
    energy_points--;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(){
    if (hit_points <= 0){
        std::cout << "ScavTrap " << name << " is dead!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " destroyed!" << std::endl;
}