#include "matrix.h"


// okt 23 jovo kedd c++ potlas

Matrix::Matrix( int mRows, int mCols)
{
    if(mRows<=0 || mRows>3000 || mCols<=0 || mCols>3000){
        throw domain_error("Ilyen matrixot nem lehet lefoglalni...");
    }
    this->mRows = mRows;
    this->mCols = mCols;
    this->mElements = new double*[mRows];
    for (int i=0; i<this->mRows; i++){
        this->mElements[i] = new double[mCols];

    }
}

Matrix::Matrix( const Matrix& what )
{
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = new double*[mRows];
    for (int i=0; i<this->mRows; i++){
        this->mElements[i] = new double[mCols];
        for(int j=0; j<this->mCols; j++){
            this->mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::~Matrix()
{
    for (int i=0; i<this->mRows; i++){
        delete[] mElements[i];
    }
    delete[] mElements;
    //cout<<"\nDestructor finished"<<endl;
}

void Matrix::fillMatrix( double value )
{
    if(value>DBL_MAX || value<-DBL_MAX) {throw new domain_error("Tul nagy/kicsi szam...");}
    for(int i=0;i<this->mRows; i++){
        for(int j=0;j<this->mCols; j++){
            this->mElements[i][j] = value;
        }
    }
}

void Matrix::randomMatrix( int a, int b )
{
    srand(time(0));
    double randomNumber;
    for(int i=0; i<this->mRows; i++){
        for(int j=0; j<this->mCols; j++){
            randomNumber = a + (rand() % ( b - a ) );
            // min + rand() % (( max + 1 ) - min);
            this->mElements[i][j] = randomNumber;
        }
    }

}

void Matrix::printMatrix( ostream& os ) const
{
    for(int i=0; i<this->mRows; i++){
      for(int j=0; j<this->mCols; j++){
            os<< this->mElements[i][j] <<" ";
      }
      os << endl;
    }
}

bool Matrix::isSquare() const
{
    return !(this->mCols - this->mRows);
}
