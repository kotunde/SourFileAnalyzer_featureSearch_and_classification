#include <iostream>
#include "pont.h"
#include "function.h"
#include <ctime>

using namespace std;

int main()
{
    //Pont A,B,C,D;
    Pont A(10, 10), B(10, 10), C(10, 10), D(10, 10);
    if(isSquare(A, B, C, D))
        cout<<"Is a square.";
    else
        cout<<"Is is not a square.";
//    if(isSquare(A(10, 10), B(10, 10), C(10, 10), D(10, 10))) cout<<"Is a square."; else cout<<"Is is not a square.";
//    if(isSquare(A(10, 10), B(10, 20), C(10, 10), D(10, 20))) cout<<"Is a square."; else cout<<"Is is not a square.";
//    if(isSquare(A(10, 10), B(10, 10), C(10, 10), D(10, 20))) cout<<"Is a square."; else cout<<"Is is not a square.";
//    if(isSquare(A(10, 10), B(10, 20), C(20, 20), D(20, 10))) cout<<"Is a square."; else cout<<"Is is not a square.";
//    if(isSquare(A(10, 10), B(10, 20), C(30, 20), D(30, 10))) cout<<"Is a square."; else cout<<"Is is not a square.";
//    if(isSquare(A(10, 10), B(20, 20), C(30, 20), D(20, 10))) cout<<"Is a square."; else cout<<"Is is not a square.";
//    if(isSquare(A(10, 10), B(20, 20), C(30, 10), D(20, 0))) cout<<"Is a square."; else cout<<"Is is not a square.";
//    if(isSquare(A(10, 10), B(20, 10), C(30, 10), D(40, 10))) cout<<"Is a square."; else cout<<"Is is not a square.";
//    if(isSquare(A(10, 10), B(20, 10), C(30, 10), D(30, 20))) cout<<"Is a square."; else cout<<"Is is not a square.";
//    if(isSquare(A(10, 10), B(30, 10), C(20, 0), D(20, 20))) cout<<"Is a square."; else cout<<"Is is not a square.";

    clock_t begin = clock();

        generate_set();

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout<<"Generalashoz szukseges ido: "<<elapsed_secs<<endl;
    //print(points);





    return 0;
}
