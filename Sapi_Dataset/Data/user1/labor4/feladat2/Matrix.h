#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;
class Matrix{
public:
 Matrix( int mRows = 10, int mCols =10);
 Matrix( const Matrix& what );
 Matrix( Matrix&& what);
 ~Matrix();

 //fills the matrix with identical elements
 void fillMatrix( double value );
 //fills the matrix with random numbers in the range [a, b)
 void randomMatrix( int a, int b );
 //prints the matrix
 void printMatrix( ostream& os = cout ) const;
 //checks whether this matrix is a square one
 bool isSquare() const;
 int getRows() const {return this->mRows;}
 int getCols() const {return this->mCols;}

 //csak egyenlo meretu matrixok eseteben engedelyezzuk az osszeadast
 //maskeppen valtson ki out_of_range kivetelt
 friend Matrix operator+(const Matrix& x, const Matrix& y);
 //nem megfelelo meretu matrixok eseten valtodjon ki kivetel
 friend Matrix operator*(const Matrix& x, const Matrix& y);
 friend istream & operator>>(istream& is, Matrix& mat);
 friend ostream & operator<<(ostream& os, const Matrix& mat);
 double* operator[] (int index);
 double* operator[] (int index) const;

 //csak egyenlo meretu matrixok eseteben engedelyezzuk az ertekadast
 //maskeppen valtson ki out_of_range kivetelt
 Matrix & operator=(const Matrix& mat);// Move assignment
 Matrix & operator=(Matrix&& mat);

private:
 double ** mElements;
 int mRows; //number of rows
 int mCols; //number of columns
};
#endif /* MATRIX_H */
