#include <iostream>
#include "Matrix.h"
#include <time.h>


Matrix::Matrix(int mRows, int mCols) {
	this->mRows = mRows;
	this->mCols = mCols;
	 mElements = new double*[mRows];
	for (int i = 0; i < mRows; ++i) {
		mElements[i] = new double [mCols];
	}
	
}

void Matrix::fillMatrix(double value) {
	for (int i = 0; i < mRows; ++i) {
		for (int j = 0; j < mCols; ++j) {
			mElements[i][j] = value;
		}
	}
}

void Matrix::randomMatrix(int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < mRows; ++i) {
		for (int j = 0; j < mCols; ++j) {
			mElements[i][j] = (double)((rand() / (double)RAND_MAX)*(max-min)+min);
		}
	}
}

void Matrix::printMatrix(ostream& os) const {
	for (int i = 0; i < mRows; ++i) {
		for (int j = 0; j < mCols; ++j) {
			os << mElements[i][j] << ' ';
		}
		os << endl;
	}
}

bool Matrix::isSquare() const {
	return mRows == mCols;
}

Matrix::Matrix(const Matrix& what) {
	this->mElements = new double*[mRows];
	for (int i = 0; i < mRows; ++i) {
		this->mElements[i] = new double[mCols];
		for (int j = 0; j < mCols; ++j) {
			this->mElements[i][j] = what.mElements[i][j];
		}
	}
}

Matrix::~Matrix() {			
	
	for (int i = 0; i < mRows; ++i) {
		delete[] mElements[i];
	}
	delete[]mElements;
}