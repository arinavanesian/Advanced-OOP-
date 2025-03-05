#pragma once
#include "point.h"

class line01
{
public:
	line01(double new_x1, double new_y1, double new_x2, double new_y2);

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
	double x1, y1, len, ang;
};

