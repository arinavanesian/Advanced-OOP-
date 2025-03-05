#pragma once
#include "point.h"

class line4
{
public:
	line4(point& that_p1, point& that_p2);
	
	double get_x();
	double get_y();
	int int_x();
	int int_y();
	
	double end_x();
	double end_y();
	int ent_x();
	int ent_y();

	double length();
	double slope();

	void shift(double dx, double dy);
	void rotate(double da);

private:
	point *start, *end;
};

