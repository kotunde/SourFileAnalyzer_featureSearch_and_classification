#include "Matrix.h"
#include <cstdlib>
#include <iostream>
#include<time.h>

using namespace std;
 Matrix::Matrix( int mRows , int mCols )
{
    this->mRows=mRows;
    this->mCols=mCols;
    mElements=new double*[mRows];
    int i;
    for(i=0; i<=mRows; ++i)
    {
        mElements[i]=new double [mCols];
    }
}
Matrix:: Matrix(  const Matrix& what )
{   int i,j;
    this->mRows=what.mRows;
    this->mCols=what.mCols;
    mElements=new double*[mRows];
    for(i=0; i<=mRows; ++i)
    {
        mElements[i]=new double [mCols];
    }
    for( i=0;i<mRows;++i)
    {
        for( j=0;j<mCols;++j)
        {
            mElements[i][j]=what.mElements[i][j];
        }
    }
}
Matrix::~Matrix(){
int i;
for(i=0;i<this->mRows;++i){
    if(mElements[i]!=nullptr){
        delete [] mElements[i];
    }
}
delete[] mElements;
}
void Matrix::fillMatrix( double value ){
for (int i = 0; i < mRows; ++i) {
		for (int j = 0; j < mCols; ++j) {
			mElements[i][j] = value;
		}
	}

}
 void Matrix::randomMatrix( int a, int b ){
srand(time(0));
	for (int i = 0;i < mRows; ++i) {
		for (int j = 0; j < mCols;++j) {
			mElements[i][j] = rand() % b-a;
		}
	}

 }
void Matrix::printMatrix(ostream& os ) const {
    for (int i = 0; i < mRows; ++i) {
		for (int j = 0; j < mCols; ++j) {
			os << mElements[i][j] << " ";
		}
		os  << endl;
	}
 }
 bool Matrix::isSquare() const{
return mRows == mCols ? true : false;
 }
