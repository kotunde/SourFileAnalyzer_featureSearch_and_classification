#include "matrix.h"
#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;

Matrix::Matrix(int mRows, int mCols)
{
	this->mCols = mCols;
	this->mRows = mRows;
	this->mElements = new double*[this->mRows];
	for (int i = 0; i < this->mRows; ++i) {
		this->mElements[i] = new double[this->mCols];
	}
}

Matrix::Matrix(const Matrix & what)
{
	this->mRows = what.mRows;
	this->mCols = what.mCols;
	this->mElements = new double*[this->mRows];
	for (int i = 0; i < this->mRows; ++i) {
		this->mElements[i] = new double[this->mCols];
	}
	for (int i = 0; i < this->mRows; ++i) {
		for (int j = 0; j < this->mCols; ++j) {
			this->mElements[i][j] = what.mElements[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < this->mRows; ++i) {
		delete[] this->mElements[i];
	}
	delete[] this->mElements;
}

void Matrix::fillMatrix(double value)
{
	for (int i = 0; i < this->mRows; ++i) {
		for (int j = 0; j < this->mCols; ++j) {
			this->mElements[i][j] = value;
		}
	}
}

void Matrix::randomMatrix(int a, int b)
{
	srand(time(NULL));
	for (int i = 0; i < this->mRows; ++i) {
		for (int j = 0; j < this->mCols; ++j) {
			this->mElements[i][j] = rand() % (b + 1 - a) + a;
		}
	}
}

void Matrix::printMatrix(ostream & os) const
{
	for (int i = 0; i < this->mRows; ++i) {
		for (int j = 0; j < this->mCols; ++j) {
			os << this->mElements[i][j] << "\t";
		}
		os << endl;
	}
	os << endl;
}

bool Matrix::isSquare() const
{
	if (this->mRows == this->mCols) {
		return true;
	}
	else {
		return false;
	}
}
