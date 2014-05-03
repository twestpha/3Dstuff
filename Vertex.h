#pragma once
#include "Matrix.h"

class Vertex{
private:
	double x, y, z;
public:
	Vertex(void);
	Vertex( double, double, double);
	~Vertex(void);
	double getX();
	double getY();
	double getZ();
	Matrix toMatrix();
};

