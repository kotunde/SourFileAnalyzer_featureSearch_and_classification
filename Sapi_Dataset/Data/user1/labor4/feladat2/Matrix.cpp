#include "Matrix.h"
#include <cstdlib>

Matrix::Matrix(int mRows, int mCols){
    this->mRows = mRows;
    this->mCols = mCols;

    this->mElements = new double*[mRows];
    for (int i = 0; i < mRows; ++i){
        this->mElements[i] = new double[mCols];
    }
}

Matrix::Matrix(const Matrix& what){
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = new double*[mRows];
    for (int i = 0; i < mRows; ++i){
        this->mElements[i] = new double[mCols];
    }
    for (int i = 0; i < mRows; ++i){
        for (int j = 0; j < mCols; ++j){
            this->mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::~Matrix(){
    for (int i = 0; i < mRows; ++i){
        delete[] mElements[i];
    }
    delete[] mElements;
}

void Matrix::fillMatrix(double value){
    for (int i = 0; i < mRows; ++i){
        for (int j = 0; j < mCols; ++j){
            mElements[i][j] = value;
        }
    }
}

void Matrix::randomMatrix(int a, int b){
    for (int i = 0; i < mRows; ++i){
        for (int j = 0; j < mCols; ++j){
            double x = rand() % (b-a+1) + a;
            mElements[i][j] = x;
        }
    }
}

void Matrix::printMatrix(ostream& os) const{
    for (int i = 0; i < mRows; ++i){
        for (int j = 0; j < mCols; ++j){
            os << mElements[i][j] << " ";
        }
        os << endl;
    }
}

bool Matrix::isSquare() const {
    if (mRows == mCols){return true;}
    else {return false;}
}
