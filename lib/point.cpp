#include "point.h"


Point::Point(int _x, int _y):
    x(_x),y(_y)
{}

Point::Point(const Point& p):
    x(p.getX()),y(p.getY())
{}

int Point::getX() const { return x; }
int Point::getY() const { return y; }