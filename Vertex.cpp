#include "Vertex.h"
#include <vector>

Vertex::Vertex(void){
}

Vertex::Vertex(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
}


Vertex::~Vertex(void){
}

double Vertex::getX(){
	return x;
}

double Vertex::getY(){
	return y;
}

double Vertex::getZ(){
	return z;
}

Matrix Vertex::toMatrix(){
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
