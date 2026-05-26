#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal created!" << std::endl;
    type = "Animal";
}

Animal::~Animal()
{
    std::cout << "Animal destroyed!" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Some animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}
