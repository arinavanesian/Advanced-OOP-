#include  "line3.h"

line3::line3(double that_x1, double that_y1, double that_x2, double that_y2)
{
	ends[0].shift(that_x1, that_y1);
	ends[1].shift(that_x2, that_y2);
}

line3::line3(point& that_p1, point& that_p2) : line3(that_p1.get_x(), that_p1.get_y(), that_p2.get_x(), that_p2.get_y())
{

}

double line3::get_x()
{
	return ends[0].get_x();
}

double line3::get_y()
{
	return ends[0].get_y();
}

int line3::int_x()
{
	return ends[0].int_x();
}

int line3::int_y()
{
	return ends[0].int_y();
}

double line3::end_x()
{
	return ends[1].get_x();
}

double line3::end_y()
{
	return ends[1].get_y();
}

int line3::ent_x()
{
	return ends[1].int_x();
}

int line3::ent_y()
{
	return ends[1].int_y();
}

double line3::length()
{
	return ends[0].dist(ends[1]);
}

double line3::slope()
{
	return ends[0].dir(ends[1]);
}

void line3::shift(double dx, double dy)
{
	ends[0].shift(dx, dy); 
	ends[1].shift(dx, dy);
}

void line3::rotate(double da)
{
	double ang = slope() + da, len = length();
	ends[1].shift(
		ends[0].get_x() + len * cos(ang) - ends[1].get_x(),
		ends[0].get_y() + len * sin(ang) - ends[1].get_y());
}