#include "Point.hpp"

Point::Point():x(0),y(0){}

Point::Point(const float n1, const float n2):x(n1), y(n2){}

Point::Point(const Point &other):x(other.x), y(other.y){}

Point::~Point(){}

Point &Point::operator=(const Point &other){
    if (this != &other)
        return (*this);
    return (*this);
}

Fixed Point::getX() const{
    return (x);
}

Fixed Point::getY() const{
    return (y);
}