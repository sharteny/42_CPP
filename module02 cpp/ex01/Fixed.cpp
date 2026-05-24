#include "Fixed.hpp"
#include <cmath>

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

Fixed::Fixed(const int n){
    std::cout << "Int constructor called" << std::endl;
	this->value = n << bits;
}

Fixed::Fixed(const float f){
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(f * (1 << bits));
}

float Fixed::toFloat()const{
    return (float)this->value / (float)(1 << bits);
}

int Fixed::toInt()const{
    return this->value >> bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed){
    out << fixed.toFloat();
    return out;
}


