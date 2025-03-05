#include "line2.h"

line2::line2(double that_x1, double that_y1, double that_x2, double that_y2) : start(that_x1, that_y1), end(that_x2, that_y2)
{

}

line2::line2(point& that_p1, point& that_p2) : start(that_p1), end(that_p2)
{

}

double line2::get_x()
{
	return start.get_x();
}

double line2::get_y()
{
	return start.get_y();
}

int line2::int_x()
{
	return start.int_x();
}

int line2::int_y()
{
	return start.int_y();
}

double line2::end_x()
{
	return end.get_x();
}

double line2::end_y()
{
	return end.get_y();
}

int line2::ent_x()
{
	return end.int_x();
}

int line2::ent_y()
{
	return end.int_y();
}

double line2::length()
{
	return start.dist(end);
}

double line2::slope()
{
	return start.dir(end);
}

void line2::shift(double dx, double dy)
{
	start.shift(dx, dy);
	end.shift(dx, dy);
}

void line2::rotate(double da)
{
	double ang = slope() + da, len = length();
	end.shift(
		start.get_x() + len * cos(ang) - end.get_x(), 
		start.get_y() + len * sin(ang) - end.get_y());
}