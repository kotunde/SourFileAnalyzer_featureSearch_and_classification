#include <iostream>
#include <fstream>
#include "Diak.h"
#include "Felveteli.h" //a szarmaztatott osztalyt is include-olni kell?

using namespace std;

int main()
{
    Diak d1("Szabo","Edit", 9.85);
    Diak d2("Nagy","Marton",8.70);
    cout << d1 << endl << d2<<endl<<endl;
    if (d1<d2)
    {
        cout<<"Kisebb: "<< d1 <<endl <<"Nagyobb: "<< d2<< endl;
    }
    else
        cout <<"Kisebb: "<< d2 <<endl <<"Nagyobb: " << d1 << endl;
    cout << endl;
    cout << endl;

    Felveteli felvi1(2);
    //Diak d3()

    Felveteli felvi("diakok.txt");
    felvi.kiiratas();
    cout << endl << "RendezesABC" << endl;
    felvi.rendezesABC();
    felvi.kiiratas();
    cout << endl << "RendezesAtlag" << endl;
    felvi.rendezesAtlag();
    felvi.kiiratas();

    ofstream f;
    f.open("diakok_out.txt");
    f << "Bejutottak:" << endl;
    felvi.bejutottak(f);

    return 0;
}