#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <stdexcept>
using namespace std;
class Matrix {
public:
	
	Matrix(int mRows = 10, int mCols = 10);	// Default constructor
	Matrix(const Matrix& what); // Copy constructor
	Matrix(Matrix&& what); // Move constructor
	~Matrix(); // Destructor

	void fillMatrix(double value); //fills the matrix with identical elements: the value
	void randomMatrix(int a, int b); //fills the matrix with random real numbers in the range [a, b)
	void printMatrix(ostream& os = cout) const; // prints the matrix
	bool isSquare() const; //checks whether this matrix is a square one
	
	int getRows() const {
		return this -> mRows;
	}
	int getCols() const {
		return this	-> mCols;
	}
	
	friend Matrix operator+(const Matrix& x, const Matrix& y); //csak egyenlo meretu matrixok eseteben engedelyezzuk az osszeadast
															   //maskeppen valtson ki out_of_range kivetelt
	
	friend Matrix operator*(const Matrix& x, const Matrix& y); //nem megfelelo meretu matrixok eseten valtodjon ki kivetel
	friend istream & operator >> (istream& is, Matrix& mat);   //inserter
	friend ostream & operator << (ostream& os, const Matrix& mat);	//extractor
	double* operator[] (int index);						
	double* operator[] (int index) const;
	
	Matrix & operator=(const Matrix& mat);  //copy asignment
											//csak egyenlo meretu matrixok eseteben engedelyezzuk az ertekadast
										   //maskeppen valtson ki out_of_range kivetelt
	
	Matrix & operator=(Matrix&& mat); // Move assignment
private:
	double ** mElements;
	int mRows; //number of rows
	int mCols; //number of columns
};
#endif
/* MATRIX_H */#pragma once
