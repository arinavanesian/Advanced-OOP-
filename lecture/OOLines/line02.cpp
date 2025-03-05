#include "line02.h"

line02::line02(double new_x1, double new_y1, double new_x2, double new_y2) : 
																		x1(new_x1), y1(new_y1), x2(new_x2), y2(new_y2)
{

}

double line02::get_x()
{
	return x1;
}

double line02::get_y()
{
	return y1;
}

int line02::int_x()
{
	return (int)(x1 + 0.5);
}

int line02::int_y()
{
	return (int)(y1 + 0.5);
}

double line02::end_x()
{
	return x2;
}

double line02::end_y()
{
	return y2;
}

int line02::ent_x()
{
	return (int)(x2 + 0.5);
}

int line02::ent_y()
{
	return (int)(y2 + 0.5);
}

double line02::length()
{
	point start(x1, y1), end(x2, y2);
	return start.dist(end);
}

double line02::slope()
{
	point start(x1, y1), end(x2, y2);
	return start.dir(end);
}

void line02::shift(double dx, double dy)
{
	x1 += dx;
	y1 += dy;
	x2 += dx;
	y2 += dy;
}

void line02::rotate(double da)
{
	double ang = slope() + da, len = length();
	x2 = x1 + len * cos(ang);
	y2 = y1 + len * sin(ang);
}