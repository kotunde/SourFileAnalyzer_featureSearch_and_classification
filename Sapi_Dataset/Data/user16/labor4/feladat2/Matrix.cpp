#include "Matrix.h"
#include <ctime>
#include <cstdlib>

Matrix :: Matrix( int mRows, int mCols )
{
    this->mRows = mRows;
    this->mCols = mCols;
    this->mElements = new double * [this->mRows];
    for (int i = 0 ; i<this->mRows ; i++)
        this->mElements[i] = new double [this->mCols];
}

Matrix :: Matrix( const Matrix & what)
{
    this->mRows = what.mRows;
    this->mCols = what.mCols;

    this->mElements = new double * [what.mRows];
    for (int i = 0 ; i<what.mRows ; i++)
        this->mElements[i] = new double [what.mCols];

    for (int i = 0 ; i<this->mRows ; i++)
        for (int j = 0 ; j<this->mCols; j++)
            this->mElements[i][j] = what.mElements[i][j];
}

void Matrix :: fillMatrix( double value )
{
    for (int i = 0 ; i<this->mRows ; i++)
        for (int j = 0 ; j<this->mCols; j++)
            this->mElements[i][j] = value;
}

void Matrix :: printMatrix(ostream& os) const
{
    for (int i = 0 ; i<this->mRows ; i++)
    {
        for (int j = 0 ; j<this->mCols; j++)
            os<<this->mElements[i][j]<<" ";
        os<<endl;
    }
    os<<endl;
}

bool Matrix :: isSquare() const
{
    return (this->mRows == this->mCols);
}

void Matrix :: randomMatrix( int a, int b )
{
    srand(time(NULL));
    for (int i = 0 ; i<this->mRows ; i++)
        for (int j = 0 ; j<this->mCols; j++)
            this->mElements[i][j] = (rand() % (b-a)) +  a;
}

Matrix :: ~Matrix()
{
    for (int i = 0 ; i<this->mRows ; i++)
        delete [] this->mElements[i];
    delete [] this->mElements;
}
