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
