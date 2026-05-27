#include "WrongCat.hpp"

WrongCat::WrongCat(){
    type = "WrongCat";
    std::cout << "Wrong Cat created!" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "Wrong Cat destroyed!" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "[Wrong] Meow meow!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return (*this);
}