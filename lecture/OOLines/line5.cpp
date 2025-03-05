#include "line5.h"

line5::line5(double that_x1, double that_y1, double that_x2, double that_y2)
{
	start = new point(that_x1, that_y1);
	end = new point(that_x2, that_y2);
}

line5::line5(point& that_p1, point& that_p2) : line5(that_p1.get_x(), that_p1.get_y(), that_p2.get_x(), that_p2.get_y())
{

}

line5::line5(line5& that) : line5(*that.start, *that.end)
{

}

line5::~line5()
{
	delete start;
	delete end;
}

double line5::get_x()
{
	return start->get_x();
}

double line5::get_y()
{
	return start->get_y();
}

int line5::int_x()
{
	return start->int_x();
}

int line5::int_y()
{
	return start->int_y();
}

double line5::end_x()
{
	return end->get_x();
}

double line5::end_y()
{
	return end->get_y();
}

int line5::ent_x()
{
	return end->int_x();
}

int line5::ent_y()
{
	return end->int_y();
}

double line5::length()
{
	return start->dist(*end);
}

double line5::slope()
{
	return start->dir(*end);
}

void line5::shift(double dx, double dy)
{
	start->shift(dx, dy);
	end->shift(dx, dy);
}

void line5::rotate(double da)
{
	double ang = slope() + da, len = length();
	end->shift(
		start->get_x() + len * cos(ang) - end->get_x(),
		start->get_y() + len * sin(ang) - end->get_y());
}