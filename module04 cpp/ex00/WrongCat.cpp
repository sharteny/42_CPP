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