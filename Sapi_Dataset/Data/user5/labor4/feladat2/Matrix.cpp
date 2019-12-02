#include "Matrix.h"
#include <cstdlib>
#include <ctime>

Matrix::Matrix(int mRows, int mCols) : mRows(mRows),
mCols(mCols), mElements(new double*[mRows]) {
	for (int i = 0; i < mRows; i++) {
		mElements[i] = new double[mCols];
	}
}

Matrix::Matrix(const Matrix& what): mRows(what.mRows), mCols(what.mCols), mElements(new double*[what.mRows]) {
	for (int i = 0; i < this->mRows; i++) {
		mElements[i] = new double[mCols];
	}
	for (int i = 0; i < this->mRows; i++) {
		for (int j = 0; j < this->mCols; j++) {
			this->mElements[i][j] = what.mElements[i][j];
		}
	}
}

Matrix::~Matrix() {
	if (mElements != nullptr) {
		for (int i = 0; i < mRows; i++) {
			delete[] mElements[i];
		}
		delete[] mElements;
	}
}

void Matrix::fillMatrix(double value) {
	for (int i = 0; i < this->mRows; i++) {
		for (int j = 0; j < this->mCols; j++) {
			this->mElements[i][j] = value;
		}
	}
}

void Matrix::randomMatrix(int a, int b) {
	srand(time(0));
	for (int i = 0; i < this->mRows; i++) {
		for (int j = 0; j < this->mCols; j++) {
			mElements[i][j] = rand() % b + a;
		}
	}
}

void Matrix::printMatrix(ostream& os) const {
	for (int i = 0; i < this->mRows; i++) {
		for (int j = 0; j < this->mCols; j++) {
			os << mElements[i][j] << " ";
		}
		os << endl;
	}
	os << endl;
}

bool Matrix::isSquare() const {
	return this->mCols == this->mRows;
}