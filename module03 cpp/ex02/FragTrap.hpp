#ifndef FRAGTRAP_HPP
#define FRAGRRAP_HPP
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap{
    public:

        FragTrap(const std::string &name);
        ~FragTrap();

        void highFivesGuys(void);

};

#endif