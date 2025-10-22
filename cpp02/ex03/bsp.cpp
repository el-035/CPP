#include "Point.hpp"

bool check_side(Point const a, Point const b, Point const c, Point const p)
{
	Fixed inside = (b.getX() - a.getX()) * (c.getY() - a.getY()) - (b.getY() - a.getY()) * (c.getX() - a.getX());
	Fixed target = (b.getX() - a.getX()) * (p.getY() - a.getY()) - (b.getY() - a.getY()) * (p.getX() - a.getX());
	if (target == 0)
		return false;
	if (inside.getRawBits() > 0 && target.getRawBits() > 0)
		return true;
	else if (inside.getRawBits() < 0 && target.getRawBits() < 0)
		return true;
	return false;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (!check_side(a, b, c, point))
		return false;
	if (!check_side(b, c, a, point))
		return false;
	if (!check_side(c, a, b, point))
		return false;
	return true;
}