#include "line8.h"

line8::line8(point& that_p1, point& that_p2) : ends(new point*[2])
{
	ends[0] = &that_p1;
	ends[1] = &that_p2;
}

line8::line8(line8& that) : line8(*that.ends[0], *that.ends[1])
{

}

line8::~line8()
{
	delete[] ends;
}

double line8::get_x()
{
	return ends[0]->get_x();
}

double line8::get_y()
{
	return ends[0]->get_y();
}

int line8::int_x()
{
	return ends[0]->int_x();
}

int line8::int_y()
{
	return ends[0]->int_y();
}

double line8::end_x()
{
	return ends[1]->get_x();
}

double line8::end_y()
{
	return ends[1]->get_y();
}

int line8::ent_x()
{
	return ends[1]->int_x();
}

int line8::ent_y()
{
	return ends[1]->int_y();
}

double line8::length()
{
	return ends[0]->dist(*ends[1]);
}

double line8::slope()
{
	return ends[0]->dir(*ends[1]);
}

void line8::shift(double dx, double dy)
{
	ends[0]->shift(dx, dy);
	ends[1]->shift(dx, dy);
}

void line8::rotate(double da)
{
	double ang = slope() + da, len = length();
	ends[1]->shift(
		ends[0]->get_x() + len * cos(ang) - ends[1]->get_x(),
		ends[0]->get_y() + len * sin(ang) - ends[1]->get_y());
}
