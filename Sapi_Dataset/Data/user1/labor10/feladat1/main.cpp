#include <iostream>
#include <algorithm>
#include <vector>
#include "Diak.h"
#include "Felveteli.h"
using namespace std;

int main()
{
    /*Diak d1("Nagy","Anna",7.65);
    Diak d2("Balint","Istvan",9.40);

    vector<Diak> diakok; diakok.push_back(d1); diakok.push_back(d2);

    cout << "Rendezes elott: \n";
    for (unsigned int i = 0; i < diakok.size(); ++i){
        cout << diakok[i];
    }

    cout << "\nRendezes utan: \n";
    sort(diakok.begin(),diakok.end());
    for (unsigned int i = 0; i < diakok.size(); ++i){
        cout << diakok[i];
    }*/
    Felveteli f(5);
    Diak d1("Nagy","Anna",7.65);
    Diak d2("Balint","Istvan",2.40);

    f.beiratkozas(d1); f.beiratkozas(d2);
    f.kiiratas(cout);

    f.rendezesAtlag();
    f.bejutottak(cout);

    return 0;
}
