#pragma once
#include <vector>

using namespace std;

struct Matrix{
	int rows, columns;
	vector< vector<double> > arr; // Pointer to (dynamic) array of doubles
	// ROWS THEN COLUMNS
	Matrix(void);
	Matrix(vector< vector<double> >, int r, int c);
	~Matrix(void);
	void print();
	Matrix operator* (const Matrix);
	Matrix operator- (const Matrix);
};

