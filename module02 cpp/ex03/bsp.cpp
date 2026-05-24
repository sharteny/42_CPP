#include "Point.hpp"

static Fixed cross(Point const& origin, Point const& a, Point const& b)
{
    return (a.getX() - origin.getX()) * (b.getY() - origin.getY())
         - (a.getY() - origin.getY()) * (b.getX() - origin.getX());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed AB = cross(a, b, point);
    Fixed BC = cross(b, c, point);
    Fixed CA = cross(c, a, point);

    if (AB == 0 || BC == 0 || CA == 0)
        return false;

    return !(((AB > 0) || (BC > 0) || (CA > 0) )&& ((AB < 0) || (BC < 0) || (CA < 0)));
}