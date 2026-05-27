#include "Cat.hpp"

Cat::Cat(){
    type = "Cat";
    std::cout << "Cat created!" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destroyed!" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow meow!" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return (*this);
}