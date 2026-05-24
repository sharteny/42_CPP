#include "Fixed.hpp"
#include <cmath>

void Fixed::setRawBits(int const raw){
    this->value = raw;
}

int Fixed::getRawBits()const{
    return this->value;
}

Fixed::Fixed() : value(0){
}

Fixed::Fixed(const Fixed& other){
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other){
    this->value = other.getRawBits();
    return *this;
}

Fixed::~Fixed(){
}

Fixed::Fixed(const int n){
	this->value = n << bits;
}

Fixed::Fixed(const float f){
    this->value = roundf(f * (1 << bits));
}

float Fixed::toFloat()const{
    return (float)this->value / (float)(1 << bits);
}

int Fixed::toInt()const{
    return this->value >> bits;
}

bool Fixed::operator==(const Fixed & other) const{
    return (this->value == other.value);
}

bool Fixed::operator!=(const Fixed & other) const{
    return !(this->value == other.value);
}

bool Fixed::operator<=(const Fixed & other) const{
    return (this->value <= other.value);
}

bool Fixed::operator>=(const Fixed & other) const{
    return (this->value >= other.value);
}

bool Fixed::operator<(const Fixed & other) const{
    return (this->value < other.value);
}

bool Fixed::operator>(const Fixed & other) const{
    return (this->value > other.value);
}

Fixed Fixed::operator +(const Fixed & other) const{
    return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator -(const Fixed & other) const{
    return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator *(const Fixed & other) const{
    return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator /(const Fixed & other) const{
    if(other.value == 0)
        return (0);
    return (this->toFloat() / other.toFloat());
}

Fixed & Fixed::operator++(){
    (this->value)++;
    return(*this);
}

Fixed & Fixed::operator--(){
    (this->value)--;
    return(*this);
}

Fixed Fixed::operator++(int){
    Fixed fix = *this;
    (this->value)++;
    return(fix);
}

Fixed Fixed::operator--(int){
    Fixed fix = *this;
    (this->value)--;
    return(fix);
}

Fixed& Fixed::min(Fixed &fix1, Fixed &fix2){
    if(fix1 > fix2)
        return (fix2);
    else
        return (fix1);

}
Fixed & Fixed::max(Fixed &fix1, Fixed &fix2){
    if(fix1 > fix2)
        return (fix1);
    else
        return (fix2);
}
const Fixed & Fixed::min(const Fixed &fix1, const Fixed &fix2){
    if(fix1 > fix2)
        return (fix2);
    else
        return (fix1);
}
const Fixed &Fixed::max(const Fixed &fix1, const Fixed &fix2){
    if(fix1 > fix2)
        return (fix1);
    else
        return (fix2);
}
std::ostream& operator<<(std::ostream& out, const Fixed& fixed){
    out << fixed.toFloat();
    return out;
}


