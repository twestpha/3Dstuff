#include "Matrix.h"
#include <stdio.h>
#include <assert.h>

using namespace std;

Matrix::Matrix(void){

}

Matrix::Matrix(vector< vector<double> > arr, int r, int c){
	this->arr = arr;
	rows = r;
	columns = c;
}


Matrix::~Matrix(void){
	
}

void Matrix::print(){
	for(int i(0); i < arr.size(); ++i){
		vector<double> row = arr.at(i);
		for(int j(0); j < arr.at(0).size(); ++j){
			printf("%f ", row[j] );
		}
		printf("\n");
	}
}

Matrix Matrix::operator*(Matrix m){

	double sum;
	assert(this->columns == m.rows); // assert that the matrices CAN be multiplied

	vector< vector<double>> product;

	for(int i(0); i < this->rows; ++i){
		vector<double> row;
		for(int j(0); j < m.columns; ++j){
			sum = 0.0;
			for(int k(0); k < this->columns; ++k){
				sum += (this->arr[i][k] * m.arr[k][j]);
			}
			row.push_back(sum);
		}
		product.push_back(row);
	}

	return Matrix(product, this->rows, m.columns);
}

Matrix Matrix::operator-(Matrix m){
	assert(this->rows == m.rows);
	assert(this->columns == m.columns);

	vector< vector<double>> diff;

	for(int i(0); i < rows; ++i){
		vector<double> row;
		vector<double> rowA = arr[i];
		vector<double> rowB = m.arr[i];
		for(int j(0); j < columns; ++j){
			row.push_back(rowA[j]-rowB[j]);
		}
		diff.push_back(row);
	}

	return Matrix(diff, this->rows, this->columns);
}