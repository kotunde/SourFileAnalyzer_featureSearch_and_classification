#include <cstdlib>
#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <random>

using namespace std;

Matrix::Matrix(int mRows, int mCols) {
	this->mRows = mRows;
	this->mCols = mCols;
	mElements = new double*[mRows];
	for (int i = 0; i < mRows; ++i) {
		mElements[i] = new double[mCols];
	}
	cout << mRows << " x " << mCols << endl;
}
Matrix::Matrix(const Matrix& what) {
	this->mElements = new double*[mRows];
	for (int i = 0; i < this->mRows; ++i) {
		this->mElements[i] = new double[mCols];
		for (int j = 0; j < this->mCols; ++j) {
			this->mElements[i][j] = what.mElements[i][j];
		}
	}
}

Matrix::~Matrix() {
	for (int i=0 ; i < mRows; ++i) {
		delete []mElements[i];
	}
	delete [] mElements;
}

void Matrix::fillMatrix(double value) {
	for (int i = 0; i < mRows; ++i) {
		for (int j = 0; j < mCols; ++j) {
			mElements[i][j] = value;
		}
	}
}
void Matrix::randomMatrix(int a, int b) {
	srand(time(0));
	int range = b - a + 1;
	for (int i = 0; i < mRows; ++i) {
		for (int j = 0; j < mCols; ++j) {
			mElements[i][j] = rand() % range + a;
		}
	}
}

void Matrix::printMatrix(ostream& os ) const{
	for (int i = 0; i < mRows; ++i) {
		for (int j = 0; j < mCols; ++j) {
			os <<  i << "," << j <<  "[" <<mElements[i][j] << "] " ;
		}
		os << endl;
	}
}

bool Matrix::isSquare() const {
	return mRows == mCols;
}
