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

Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    this->type = other.type;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return (*this);
}