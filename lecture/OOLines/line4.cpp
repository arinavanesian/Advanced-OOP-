#include "line4.h"

line4::line4(point& that_p1, point& that_p2) : start(&that_p1), end(&that_p2)
{

}

double line4::get_x()
{
	return start->get_x();
}

double line4::get_y()
{
	return start->get_y();
}

int line4::int_x()
{
	return start->int_x();
}

int line4::int_y()
{
	return start->int_y();
}

double line4::end_x()
{
	return end->get_x();
}

double line4::end_y()
{
	return end->get_y();
}

int line4::ent_x()
{
	return end->int_x();
}

int line4::ent_y()
{
	return end->int_y();
}

double line4::length()
{
	return start->dist(*end);
}

double line4::slope()
{
	return start->dir(*end);
}

void line4::shift(double dx, double dy)
{
	start->shift(dx, dy);
	end->shift(dx, dy);
}

void line4::rotate(double da)
{
	double ang = slope() + da, len = length();
	end->shift(
		start->get_x() + len * cos(ang) - end->get_x(),
		start->get_y() + len * sin(ang) - end->get_y());
}