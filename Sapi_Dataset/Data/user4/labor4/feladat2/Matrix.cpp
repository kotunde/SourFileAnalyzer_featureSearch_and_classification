#include "Matrix.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Matrix :: Matrix( int mRows, int mCols)
{
    this->mRows = mRows;
    this->mCols = mCols;
    this->mElements = new double*[mRows];
    for(int i = 0; i < mRows; i++)
    {
        mElements[i] = new double[mCols];
    }
}

Matrix :: Matrix( const Matrix& what )
{
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = new double*[mRows];
    for(int i = 0; i < mRows; i++)
    {
        mElements[i] = new double[mCols];
    }
    for(int i = 0; i < mRows; i++)
    {
        for(int j = 0; j < mCols; j++)
        {
            this->mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix :: ~Matrix()
{
    for(int i = 0; i < mRows; i++)
    {
        if(mElements[i] != nullptr)
        {
            delete[] mElements[i];
        }
    }
    if(mElements != nullptr)
    {
        delete[] mElements;
    }

}

void Matrix :: fillMatrix( double value )
{
    for(int i = 0; i < mRows; i++)
    {
        for(int j = 0; j < mCols; j++)
        {
            this->mElements[i][j] = value;
        }
    }
}

void Matrix :: randomMatrix( int a, int b )
{
    srand (time(NULL));
    for(int i = 0; i < mRows; i++)
    {
        for(int j = 0; j < mCols; j++)
        {
            this->mElements[i][j] = rand() % (b-a) + a;
        }
    }
}

void Matrix :: printMatrix( ostream& os ) const
{
    for(int i = 0; i < mRows; i++)
    {
        for(int j = 0; j < mCols; j++)
        {
            os << mElements[i][j] << " ";
        }
        os << endl;
    }
}

bool Matrix :: isSquare() const
{

    return mRows == mCols;
}
















