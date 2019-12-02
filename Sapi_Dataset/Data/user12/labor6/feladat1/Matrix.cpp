#include "Matrix.h"
#include <iostream>
#include <stdexcept>

Matrix::Matrix(int n, int m){
    int i;
mRows = n;
mCols = m;
mElements = new double*[n];
for(i=0; i<m; ++i){
    mElements[i]=new double[n];
}
}
Matrix::Matrix( const Matrix& m ){
    int i,j;
mRows=m.Rows;
mCols=m.mCols;
mElements=new double*[mRows];;
for(i=0; i<mCols; ++i){
    mElements[i]=new double[mRows];;
}
for(i=0; i<mRows; ++i){
    for(j=0; j<mCols; ++j){
            mElements[i][j]=m.mElements[i][j];
    }
}
}

matrix::matrix(matrix&& what){
    mCols = what.mCols;
    mRows = what.mRows;
    mElements = what.mElements;
}

Matrix::~Matrix(){
int i;
for(i=0; i<mCols; ++i){
delete[]mElements[i];
}
delete[]mElements;
}

void Matrix::fillMatrix(double value){
int i,j;
for(i=0; i<mRows; ++i){
    for(j=0; j<mCols; ++j){
        mElements[i][j]=value;
    }
}
}

void Matrix::randomMatrix( int a, int b ){
srand(time(0));
int i,j;
for(i=0; i<mRows; ++i){
    for(j=0; j<mCols; ++j){
        mElements[i][j]=(rand()%(b-a+1))+a;
    }
}
}

void Matrix::printMatrix(ostream& os) const{
int i,j;
for(i=0; i<mRows; ++i){
    for(j=0; j<mCols; ++j){
        cout << mElements[i][j] << " ";
    }
    cout << endl;
}
}

bool Matrix::isSquare() const{
if(mRows==mCols){
    return true;
}
else{
    return false;
}
}
Matrix &Matrix:: operator=(const Matrix& mat){
if((this.mRows!=mat.getRows())||(this.mCols!=mat.getCols())){
    throw std::out_of_range ("The matrixes are not eagle");
}
for(i=0; i<mat.getRows(); ++i){
    for(j=0; j<mat.getCols(); ++j){
            this.mElements[i][j]=mat.mElements[i][j];
    }
}

}
