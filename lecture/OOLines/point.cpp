#include "point.h"

point::point(double new_x, double new_y) : x(new_x), y(new_y)
{

}

point::point() : point(0, 0)
{

}

double point::get_x()
{
	return x;
}

double point::get_y()
{
	return y;
}

int point::int_x()
{
	return (int) (x + 0.5);
}

int point::int_y()
{
	return (int) (y + 0.5);
}

double point::dist(point& that)
{
	return sqrt((x - that.x) * (x - that.x) + (y - that.y) * (y - that.y));
}

double point::dir(point& that)
{
	return atan2(that.y - y, that.x - x);
}

void point::shift(double dx, double dy)
{
	x += dx;
	y += dy;
}