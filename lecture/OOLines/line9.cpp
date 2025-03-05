#include "line9.h"

line9::line9(double that_x1, double that_y1, double that_x2, double that_y2) : ends(new point* [2])
{
	ends[0] = new point(that_x1, that_y1);
	ends[1] = new point(that_x2, that_y2);
}

line9::line9(point& that_p1, point& that_p2) : line9(that_p1.get_x(), that_p1.get_y(), that_p2.get_x(), that_p2.get_y())
{

}

line9::line9(line9& that) : line9(*that.ends[0], *that.ends[1])
{

}

line9::~line9()
{
	for (int index = 0; index < 2; index++)
		delete ends[index];

	delete[] ends;
}

double line9::get_x()
{
	return ends[0]->get_x();
}

double line9::get_y()
{
	return ends[0]->get_y();
}

int line9::int_x()
{
	return ends[0]->int_x();
}

int line9::int_y()
{
	return ends[0]->int_y();
}

double line9::end_x()
{
	return ends[1]->get_x();
}

double line9::end_y()
{
	return ends[1]->get_y();
}

int line9::ent_x()
{
	return ends[1]->int_x();
}

int line9::ent_y()
{
	return ends[1]->int_y();
}

double line9::length()
{
	return ends[0]->dist(*ends[1]);
}

double line9::slope()
{
	return ends[0]->dir(*ends[1]);
}

void line9::shift(double dx, double dy)
{
	ends[0]->shift(dx, dy);
	ends[1]->shift(dx, dy);
}

void line9::rotate(double da)
{
	double ang = slope() + da, len = length();
	ends[1]->shift(
		ends[0]->get_x() + len * cos(ang) - ends[1]->get_x(),
		ends[0]->get_y() + len * sin(ang) - ends[1]->get_y());
}
