#include <iostream>
#include <vector>
#include <fstream>
#include "Diak.h"
#include "Felveteli.h"


using namespace std;

int main()
{
    Diak a("Pal", "Janos", 6.75);
    Diak b("Gergely", "Emilia", 4.5);
    cout << a << endl << b << endl;
    if(a < b){
        cout << a << endl << b << endl;
    }
    else{
        cout << b << endl << a << endl;
    }
    cout << endl;


    Felveteli fel(2);
    Diak c("Gergely","Evelin",5.6);
    Diak d("Balazs", "Alfonz", 7);
    fel.Beiratkozas(a);
    fel.Beiratkozas(b);
    fel.Beiratkozas(c);
    fel.Beiratkozas(d);
    fel.RendezesABC();
    fel.kiiratas(cout);
    cout << endl << "Bejutottak: " << endl;
    fel.bejutottak(cout);


    Felveteli fel1("bemenet.txt");
    cout << endl;
    fel1.bejutottak(cout);
    return 0;
}
