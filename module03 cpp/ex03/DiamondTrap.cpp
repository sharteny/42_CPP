#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), name("Default")
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 30;
    std::cout << "DiamondTrap Default constructor called" <<std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
    std::cout << "DiamondTrap Copy constructor called for "<< std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name){

        this->hit_points = 100;
        this->energy_points = 50;
        this->attack_damage = 30;

        std::cout << "DiamondTrap " << this->name << " created!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "DiamondTrap Copy assignment operator called for " << std::endl;
    return (*this);
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