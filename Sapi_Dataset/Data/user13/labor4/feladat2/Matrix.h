#ifndef MATRIX_H 
#define MATRIX_H 
#include <iostream> 
							// ha constructorba hasznalunk new-t akkor a destructorba kell delete
							// ha consturctorba ki nyitunk filet, a destructorba zarjuk be 
using namespace std;
 class Matrix{ 
 public:      
	 Matrix( int mRows = 10, int mCols =10);   
	 Matrix( const Matrix& what );   //COPY CONSTRUCTOR !
	 ~Matrix();     // tilda matrix  vagyis DESTRUCTOR
	    
	 void fillMatrix( double value );    //fills the matrix with identical elements 
	  
	 void randomMatrix( int a, int b );     //fills the matrix with random numbers in the range [a, b) 
	    
	 void printMatrix( ostream& os = cout ) const;  //prints the matrix
	 
     bool isSquare() const;  //checks whether this matrix is a square one  
 private:    
	 double ** mElements;    
	 int mRows; //number of rows  
	 int mCols; //number of columns 
 };
#endif /* MATRIX_H */ 
