#include "Face.h"
#include "ofMain.h"
#include "Matrix.h"
#include <math.h>

Face::Face(void){
}

Face::Face( Vertex s, Vertex t, Vertex u, int r, int g, int b){
	this->s = s;
	this->t = t;
	this->u = u;
	this->r = r;
	this->g = g;
	this->b = b;
}

Face::~Face(void){
}

Matrix transformA(Matrix theta){
	double theta_x = theta.arr.at(0).at(0);
	double theta_y = theta.arr.at(1).at(0);
	double theta_z = theta.arr.at(2).at(0);
	// Start of transformation definition
	vector< vector<double>> m;
	vector<double> one;
	vector<double> two;
	vector<double> three;
	// row one
	one.push_back(1.0);
	one.push_back(0.0);
	one.push_back(0.0);
	// row two
	two.push_back(0.0);
	two.push_back(cos(-1 * theta_x));
	two.push_back(-1 * sin(-1 * theta_x));
	// row three
	three.push_back(0.0);
	three.push_back(sin(-1 * theta_x));
	three.push_back(cos(-1 * theta_x));
	// push them all back
	m.push_back(one);
	m.push_back(two);
	m.push_back(three);
	return Matrix(m, 3, 3);
}

Matrix transformB(Matrix theta){
	double theta_x = theta.arr.at(0).at(0);
	double theta_y = theta.arr.at(1).at(0);
	double theta_z = theta.arr.at(2).at(0);
	// Start of transformation definition
	vector< vector<double>> m;
	vector<double> one;
	vector<double> two;
	vector<double> three;
	// row one
	one.push_back(cos(-1* theta_y));
	one.push_back(0.0);
	one.push_back(sin(-1* theta_y));
	// row two
	two.push_back(0.0);
	two.push_back(1.0);
	two.push_back(0.0);
	// row three
	three.push_back(-1 * sin(-1 * theta_y));
	three.push_back(0.0);
	three.push_back(cos(-1 * theta_y));
	// push them all back
	m.push_back(one);
	m.push_back(two);
	m.push_back(three);
	return Matrix(m, 3, 3);
}

Matrix transformC(Matrix theta){
	double theta_x = theta.arr.at(0).at(0);
	double theta_y = theta.arr.at(1).at(0);
	double theta_z = theta.arr.at(2).at(0);
	// Start of transformation definition
	vector< vector<double>> m;
	vector<double> one;
	vector<double> two;
	vector<double> three;
	// row one
	one.push_back(cos(-1 * theta_z));
	one.push_back(-1 * sin(-1 * theta_z));
	one.push_back(0.0);
	// row two
	two.push_back(sin(-1 * theta_z));
	two.push_back(cos(-1 * theta_z));
	two.push_back(0.0);
	// row three
	three.push_back(0.0);
	three.push_back(0.0);
	three.push_back(1.0);
	// push them all back
	m.push_back(one);
	m.push_back(two);
	m.push_back(three);
	return Matrix(m, 3, 3);
}
void Face::draw(Camera c){
	// Declaration of point matrices, adjusted for camera tanslation
	Matrix s_matrix = s.toMatrix() - c.toMatrix();
	Matrix t_matrix = t.toMatrix() - c.toMatrix();
	Matrix u_matrix = u.toMatrix() - c.toMatrix();
	// Declaration of the transformation matrices
	Matrix a_matrix = transformA(c.rotationMatrix());
	Matrix b_matrix = transformB(c.rotationMatrix());
	Matrix c_matrix = transformC(c.rotationMatrix());
	// Now for that good 'ole down home matrix multipication
	Matrix d_s = c_matrix * s_matrix;
	Matrix d_t = c_matrix * t_matrix;
	Matrix d_u = c_matrix * u_matrix;
	// part two
	d_s = b_matrix * d_s;
	d_t = b_matrix * d_t;
	d_u = b_matrix * d_u;
	// finally, part three
	d_s = a_matrix * d_s;
	d_t = a_matrix * d_t;
	d_u = a_matrix * d_u;
	// Projecting the vertices onto the two-d plane
	double s_x = ((ofGetWidth()/2)  * c.dof *  (d_s.arr.at(2).at(0) / d_s.arr.at(0).at(0)))  + (ofGetWidth ()/2);
	double s_y = ((ofGetHeight()/2) * c.dof * (d_s.arr.at(1).at(0) / d_s.arr.at(0).at(0)))  + (ofGetHeight()/2);
																		  
	double t_x = ((ofGetWidth()/2)  * c.dof * (d_t.arr.at(2).at(0) / d_t.arr.at(0).at(0)))  + (ofGetWidth ()/2);
	double t_y = ((ofGetHeight()/2) * c.dof * (d_t.arr.at(1).at(0) / d_t.arr.at(0).at(0)))  + (ofGetHeight()/2);
																		 
	double u_x = ((ofGetWidth()/2)  * c.dof * (d_u.arr.at(2).at(0) / d_u.arr.at(0).at(0)))  + (ofGetWidth ()/2);
	double u_y = ((ofGetHeight()/2) * c.dof * (d_u.arr.at(1).at(0) / d_u.arr.at(0).at(0)))  + (ofGetHeight()/2);

	//printf("s_x = %f\n", (d_s.arr.at(2).at(0) / d_s.arr.at(0).at(0)) );

	if(s.getZ() > c.x || t.getZ() > c.x || u.getZ() > c.x){ // naive clipping
		// Draw vertices
		//ofSetColor(255,255,255);
		//ofCircle(s_x,s_y,2);
		//ofCircle(t_x,t_y,2);
		//ofCircle(u_x,u_y,2);

		// Draw face
		ofSetColor(r,g,b);
		ofBeginShape();
			ofVertex(s_x,s_y);
			ofVertex(t_x,t_y);
			ofVertex(u_x,u_y);
		ofEndShape();
	}
}

