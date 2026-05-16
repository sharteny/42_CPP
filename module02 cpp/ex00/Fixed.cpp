#include "Fixed.hpp"

void Fixed::setRawBits(int const raw){
    this->value = raw;
}

int Fixed::getRawBits()const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

Fixed::Fixed() : value(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = other.getRawBits();
    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

