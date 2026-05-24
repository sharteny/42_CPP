#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{
    private:
        std::string name;
    public:
        DiamondTrap(const std::string &name);
        ~DiamondTrap();
        void    whoAmI();
        void	attack(const std::string& target);  
};

#endif