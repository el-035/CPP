#include"Point.hpp"

/* bool Point::operator==(const Point& other) const
{
	if (this->x != other.x)
		return false;
	if (this->y != other.y)
		return false;
	return true;
} */
Point::Point() : x(), y() {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point& other)  : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other)
{		//?
	(void)other;
	return *this;
}
Point::~Point() {}

Fixed Point::getX(void) const
{
	return(x);
}
Fixed Point::getY(void) const
{
	return(y);
}