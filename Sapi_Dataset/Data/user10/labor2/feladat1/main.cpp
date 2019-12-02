#include <cstdlib>
#include <iostream>
#include "Pont.h"
#include "function.h"
#include <algorithm>
#include <random>
#include <time.h>

using namespace std;

int main(int argc, char** argv){
    srand(time(NULL));

    cout << (IsSquare(Pont(10, 10),Pont(10, 10), Pont(10, 10), Pont(10, 10))?"Negyzet":"Nem az") << endl;
    cout << (IsSquare(Pont(10, 10),Pont(10, 20), Pont(10, 10), Pont(10, 10))?"Negyzet":"Nem az") << endl;
    cout << (IsSquare(Pont(10, 10),Pont(10, 10), Pont(10, 10), Pont(10, 20))?"Negyzet":"Nem az") << endl;
    cout << (IsSquare(Pont(10, 10),Pont(10, 20), Pont(20, 20), Pont(20, 10))?"Negyzet":"Nem az") << endl;
    cout << (IsSquare(Pont(10, 10),Pont(10, 20), Pont(30, 20), Pont(30, 10))?"Negyzet":"Nem az") << endl;
    cout << (IsSquare(Pont(10, 10),Pont(20, 20), Pont(30, 20), Pont(20, 10))?"Negyzet":"Nem az") << endl;
    cout << (IsSquare(Pont(10, 10),Pont(20, 10), Pont(30, 10), Pont(40, 10))?"Negyzet":"Nem az") << endl;
    cout << (IsSquare(Pont(10, 10),Pont(20, 10), Pont(30, 10), Pont(30, 20))?"Negyzet":"Nem az") << endl;
    cout << (IsSquare(Pont(10, 10),Pont(30, 10), Pont(20, 00), Pont(20, 20))?"Negyzet":"Nem az") << endl;

    /*
    const int N = 1000000;
    Pont* pontok = dot_generator2(N, 2001, 2001);///1.000.000;///4.004.001
    cout << "KESZ";
    delete[] pontok;
    */
    return (EXIT_SUCCESS);
}
