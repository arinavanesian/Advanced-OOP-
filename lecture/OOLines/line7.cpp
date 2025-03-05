#include "line7.h"

line7::line7(double that_x1, double that_y1, double that_x2, double that_y2)
{
	ends[0] = new point(that_x1, that_y1);
	ends[1] = new point(that_x1, that_y1);
}

line7::line7(point& that_p1, point& that_p2) : line7(that_p1.get_x(), that_p1.get_y(), that_p2.get_x(), that_p2.get_y())
{

}

line7::line7(line7& that) : line7(*that.ends[0], *that.ends[1])
{
	
}

line7::~line7()
{
	for (point* ptr : ends)
		delete ptr;
}

double line7::get_x()
{
	return ends[0]->get_x();
}

double line7::get_y()
{
	return ends[0]->get_y();
}

int line7::int_x()
{
	return ends[0]->int_x();
}

int line7::int_y()
{
	return ends[0]->int_y();
}

double line7::end_x()
{
	return ends[1]->get_x();
}

double line7::end_y()
{
	return ends[1]->get_y();
}

int line7::ent_x()
{
	return ends[1]->int_x();
}

int line7::ent_y()
{
	return ends[1]->int_y();
}

double line7::length()
{
	return ends[0]->dist(*ends[1]);
}

double line7::slope()
{
	return ends[0]->dir(*ends[1]);
}

void line7::shift(double dx, double dy)
{
	ends[0]->shift(dx, dy);
	ends[1]->shift(dx, dy);
}

void line7::rotate(double da)
{
	double ang = slope() + da, len = length();
	ends[1]->shift(
		ends[0]->get_x() + len * cos(ang) - ends[1]->get_x(),
		ends[0]->get_y() + len * sin(ang) - ends[1]->get_y());
}