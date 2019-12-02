#include "matrix.h"

#include <iostream>
#include <cstdlib>
#include <time.h>

Matrix::Matrix(int mRows, int mCols){
    if(mRows>0 && mCols>0){
        this->mRows=mRows;
        this->mCols=mCols;
        this->mElements=new double*[mRows];
        for(int i=0; i<mRows; i++){
            this->mElements[i]=new double[mCols];
        }
    }
}

Matrix::Matrix( const Matrix& what ){
    this->mRows=what.mRows;
    this->mCols=what.mCols;
    this->mElements=new double*[mRows];
    for(int i=0; i<this->mRows; i++){
        this->mElements[i]=new double[mCols];
        for(int j=0; j<this->mCols; j++){
            this->mElements[i][j]=what.mElements[i][j];
        }
    }
}

Matrix::~Matrix(){
    if(this->mElements!=nullptr){
        for(int i=0; i<this->mRows; i++){
            delete[] this->mElements[i];
        }
        delete[] mElements;
    }
}

void Matrix::fillMatrix( double value ){
    if(this->mElements!=nullptr){
        for(int i=0; i<this->mRows; i++){
            for(int j=0; j<this->mCols; j++){
                this->mElements[i][j]=value;
            }
        }
    }
}

void Matrix::randomMatrix( int a, int b ){
    srand(time(0));
    if(this->mElements!=nullptr){
        for(int i=0; i<this->mRows; i++){
            for(int j=0; j<this->mCols; j++){
                this->mElements[i][j]=rand()%(b-a)+a;
            }
        }
    }
}

void Matrix::printMatrix( ostream& os) const{
    if(this->mElements!=nullptr){
        for(int i=0; i<this->mRows; i++){
            for(int j=0; j<this->mCols; j++){
                os<<this->mElements[i][j]<<" ";
            }
            os<<endl;
        }
    }
}

bool Matrix::isSquare() const{
    if(this->mRows == this->mCols){
        return true;
    }
    else{
        return false;
    }
}
