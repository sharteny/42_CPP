#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "Wrong Animal created!" << std::endl;
    type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Wrong Animal destroyed!" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Wrong Animal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (type);
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    this->type = other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return (*this);
}