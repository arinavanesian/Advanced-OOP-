#include "line1.h"

line1::line1(double that_x1, double that_y1, double that_x2, double that_y2) : start(that_x1, that_y1)
{
	point end(that_x2, that_y2);
	len = start.dist(end);
	ang = start.dir(end);
}

line1::line1(point& p1, point& p2) : start(p1)
{
	len = p1.dist(p2);
	ang = p1.dir(p2);
}

double line1::get_x()
{
	return start.get_x();
}

double line1::get_y()
{
	return start.get_y();
}

int line1::int_x()
{
	return start.int_x();
}

int line1::int_y()
{
	return start.int_y();
}

double line1::end_x()
{
	return get_x() + len * cos(ang);
}

double line1::end_y()
{
	return get_y() + len * sin(ang);
}

int line1::ent_x()
{
	return (int) (end_x() + 0.5);
}
int line1::ent_y()
{
	return (int) (end_y() + 0.5);
}

double line1::length()
{
	return len;
}

double line1::slope()
{
	return ang;
}

void line1::shift(double dx, double dy)
{
	start.shift(dx, dy);
}

void line1::rotate(double da)
{
	ang += da;
}