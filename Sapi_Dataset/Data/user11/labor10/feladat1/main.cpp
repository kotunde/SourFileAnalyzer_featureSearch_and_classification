#include <iostream>
#include "Diak.h"
#include "Felveteli.h"
#include <fstream>

using namespace std;

int main()
{
     Felveteli felv(2);
   Diak d1("Fekete","Timea",9.9);
   Diak d2("Fekete","Tekla",2.3);
   Diak d3 ("Farkas","Era",6.3);
   felv.beiratkozas(d1);
   felv.beiratkozas(d2);
   felv.beiratkozas(d3);
   cout<<"Beiratkozottak: "<<endl;
   felv.kiiratas(cout);
   felv.rendezesABC();
   cout<<"Rendezett: "<<endl;
   felv.kiiratas(cout);
   felv.rendezesAtlag();
   cout<<"Rendezett atlag: "<<endl;
   felv.kiiratas(cout);
   felv.bejutottak(cout);
    Felveteli felv1("be.txt");
    felv1.kiiratas(cout);
    return 0;
}
