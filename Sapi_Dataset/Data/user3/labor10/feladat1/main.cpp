#include <iostream>
#include <fstream>
#include "Diak.h"
#include "Felveteli.h"

using namespace std;

int main()
{
    Diak d1("Nagy","Andras",8);
    Diak d2("Szabo","Maria",9);
    cout<<"Diakok:\n\t"<<d1<<endl<<"\t"<<d2<<endl;

    cout<<"\nABC sorrend:\n";
    if(d1<d2){
        cout<<"\t"<<d1<<endl<<"\t"<<d2<<endl;
    }
    else{
        cout<<"\t"<<d2<<endl<<"\t"<<d1<<endl;
    }

    Diak d3("Fekete","Peter",6);
    Diak d4("Nagy","Katalin",9.45);
    Felveteli f1(2);
    f1.beiratkozas(d1);
    f1.beiratkozas(d2);
    f1.beiratkozas(d3);
    f1.beiratkozas(d4);

    f1.rendezesABC();
    cout<<"\nDiakok:\n";
    f1.kiiratas();
    cout<<"\nBejutottak:\n";
    f1.bejutottak();

    Felveteli f2("felveteli.txt");
    ofstream fout;
    fout.open("bejutas.txt");
    f2.bejutottak(fout);
    fout.close();
    return 0;
}
