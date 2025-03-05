#pragma once
#include "point.h"

class line02
{
public:
	line02(double that_x1, double that_y1, double that_x2, double that_y2);
	
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
	double x1, y1, x2, y2;
};

