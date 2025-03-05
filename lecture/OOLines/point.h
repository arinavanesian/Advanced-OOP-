#pragma once
#include <cmath>
class point
{
public:
	point();
	point(double new_x, double new_y);

	double get_x();
	double get_y();
	int int_x();
	int int_y();

	double dist(point& that);
	double dir(point& that);

	void shift(double dx, double dy);

private:
	double x, y;
};

