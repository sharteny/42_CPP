#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name){

        this->hit_points = 100;
        this->energy_points = 50;
        this->attack_damage = 30;

        std::cout << "DiamondTrap " << this->name << " created!" << std::endl;
}

void DiamondTrap::attack(const std::string &target){
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " destroyed!" << std::endl;
}