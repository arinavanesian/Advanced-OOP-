#include "line01.h"

line01::line01(double new_x1, double new_y1, double new_x2, double new_y2) : x1(new_x1), y1(new_y1)
{
	point start(new_x1, new_y1), end(new_x2, new_y2);
	len = start.dist(end);
	ang = start.dir(end);
}

double line01::get_x()
{
	return x1;
}

double line01::get_y()
{
	return y1;
}

int line01::int_x()
{
	return (int) (x1 + 0.5);;
}

int line01::int_y()
{
	return (int) (y1 + 0.5);;
}

double line01::end_x()
{
	return x1 + len * cos(ang);
}

double line01::end_y()
{
	return y1 + len * sin(ang);
}

int line01::ent_x()
{
	return (int) (end_x() + 0.5);
}

int line01::ent_y()
{
	return (int) (end_y() + 0.5);
}

double line01::length()
{
	return len;
}

double line01::slope() 
{
	return ang;
}

void line01::shift(double dx, double dy)
{
	x1 += dx;
	y1 += dy;
}

void line01::rotate(double da)
{
	ang += da;
}