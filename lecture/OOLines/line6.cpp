#include "line6.h"

line6::line6(point& that_p1, point& that_p2)
{
	ends[0] = &that_p1;
	ends[1] = &that_p2;
}

double line6::get_x()
{
	return ends[0]->get_x();
}

double line6::get_y()
{
	return ends[0]->get_y();
}

int line6::int_x()
{
	return ends[0]->int_x();
}

int line6::int_y()
{
	return ends[0]->int_y();
}

double line6::end_x()
{
	return ends[1]->get_x();
}

double line6::end_y()
{
	return ends[1]->get_y();
}

int line6::ent_x()
{
	return ends[1]->int_x();
}

int line6::ent_y()
{
	return ends[1]->int_y();
}

double line6::length()
{
	return ends[0]->dist(*ends[1]);
}

double line6::slope()
{
	return ends[0]->dir(*ends[1]);
}

void line6::shift(double dx, double dy)
{
	ends[0]->shift(dx, dy);
	ends[1]->shift(dx, dy);
}

void line6::rotate(double da)
{
	double ang = slope() + da, len = length();
	ends[1]->shift(
		ends[0]->get_x() + len * cos(ang) - ends[1]->get_x(),
		ends[0]->get_y() + len * sin(ang) - ends[1]->get_y());
}