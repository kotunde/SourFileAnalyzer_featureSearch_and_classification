#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <iostream>

using namespace std;

class Matrix{
    public:
        Matrix( int mRows = 10, int mCols =10);
        Matrix( const Matrix& what ); //mely masolat - deep copy - klonozas
        ~Matrix();

        //fills the matrix with identical elements
        void fillMatrix( double value );
        //fills the matrix with random numbers in the range [a, b)
        void randomMatrix( int a, int b );
        //prints the matrix
        void printMatrix( ostream& os = cout ) const;
        //checks whether this matrix is a square one
        bool isSquare() const;

    private:
         double ** mElements;
         int mRows; //number of rows
         int mCols; //number of columns
};

#endif // MATRIX_H_INCLUDED
