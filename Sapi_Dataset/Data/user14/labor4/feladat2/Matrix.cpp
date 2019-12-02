//
// Created by tuni on 10/15/18.
//

#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols)
{
    this->mRows=mRows;
    this->mCols=mCols;
    this->mElements=new double*[mRows];
    for (int i=0; i<mRows; ++i)
    {
        mElements[i]=new double[mCols];
    }
}

Matrix::Matrix(const Matrix &what)
{
    this->mRows=what.mRows;
    this->mCols=what.mCols;
    this->mElements=new double*[mRows];
    int i,j;
    for (i=0; i<mRows; ++i)
    {
        mElements[i]=new double[mCols];
    }
    for(i=0; i<mRows; ++i)
    {
        for (j=0; j<mCols; ++j)
        {
            this->mElements[i][j]=what.mElements[i][j];
        }
    }

}

Matrix::~Matrix()
{
    for (int i=0; i<mRows; ++i)
    {
        delete [] mElements[i];
    }
    delete [] mElements;
}

void Matrix::fillMatrix(double value)
{
    for (int i=0; i<mRows; ++i)
    {
        for(int j=0; j<mCols; ++j)
        {
            this->mElements[i][j]=value;
        }
    }
}

void Matrix::randomMatrix(int a, int b)
{
    for (int i=0; i<mRows; ++i)
    {
        for(int j=0; j<mCols; ++j)
        {
            this->mElements[i][j]=(rand()%(b-a))+a;
        }
    }
}

void Matrix::printMatrix(ostream &os) const
{
    for (int i=0; i<mRows; ++i)
    {
        for(int j=0; j<mCols; ++j)
        {
            cout << mElements[i][j] << " ";
        }
        cout<< endl;
    }
}

bool Matrix::isSquare() const
{
    if (mRows==mCols)
    {
        return true;
    }
    return false;
}
