#include"Point.hpp"

/* bool Point::operator==(const Point& other) const
{
	if (this->x != other.x)
		return false;
	if (this->y != other.y)
		return false;
	return true;
} */
Point::Point()
{

}
Point::Point(const float x, const float y)
{

}
Point::Point(const Point& other)
{

}
Point& Point::operator=(const Point& other)
{

}
Point::~Point()
{

}

Fixed Point::getX(void) const
{
	return(x);
}
Fixed Point::getY(void) const
{
	return(y);
}