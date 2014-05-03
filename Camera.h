#pragma once
#include "Matrix.h"

class Camera{
public:
	double x, y, z; 
	double rotx, roty, rotz; 
	double dof;
	// rotx = pitch
	// roty = roll
	// rotz = yaw
	// def = depth of field
	// all in radians, 0 - 6.28 (0-360 deg)
	Camera(void);
	Camera( double, double, double, double, double, double, double );
	~Camera(void);
	Matrix toMatrix();
	Matrix rotationMatrix();
};

