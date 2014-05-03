#include "Camera.h"
#include "Matrix.h"

Camera::Camera(void){
	x = 0;
	y = 0;
	z = 0;
	rotx = 0;
	roty = 0;
	rotz = 0;
	dof = 0;
}

Camera::Camera( double x, double y, double z, double rotx, double roty, double rotz, double dof ){
	this->x = x;
	this->y = y;
	this->z = z;
	this->rotx = rotx;
	this->roty = roty;
	this->rotz = rotz;
	this->dof = dof;
}

Camera::~Camera(void){
}

Matrix Camera::toMatrix(){
	vector< vector<double>> m;
	vector<double> one;
	vector<double> two;
	vector<double> three;
	one.push_back(this->x);
	two.push_back(this->y);
	three.push_back(this->z);
	m.push_back(one);
	m.push_back(two);
	m.push_back(three);
	return Matrix(m, 3, 1);
}

Matrix Camera::rotationMatrix(){
	vector< vector<double>> m;
	vector<double> one;
	vector<double> two;
	vector<double> three;
	one.push_back(this->rotx);
	two.push_back(this->roty);
	three.push_back(this->rotz);
	m.push_back(one);
	m.push_back(two);
	m.push_back(three);
	return Matrix(m, 3, 1);
}