#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap(){
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap Copy constructor called for " <<std::endl;

}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap Copy assignment operator called for " << std::endl;
    return (*this);
}

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

