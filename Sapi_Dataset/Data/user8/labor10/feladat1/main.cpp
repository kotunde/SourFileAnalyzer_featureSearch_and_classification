#include <iostream>
#include <algorithm>
#include <vector>
#include "diak.h"
#include "felveteli.h"
using namespace std;

int main()
{
    cout << "Diak teszt" << endl;

    Diak d1("Kis", "Diak", 1996);
    Diak d2("Nagy", "Diak", 1998);

    cout<<d1<<d2;
    cout<<endl;
    vector<Diak>diakok;
    diakok.push_back(d1);
    diakok.push_back(d2);
    diakok.push_back(Diak("Kis", "Diak", 2003));
    diakok.push_back(Diak("Kisebb", "Diak", 2003));
    diakok.push_back(Diak("Nagyobb", "Diak", 2003));

    sort(diakok.begin(), diakok.end());
    for(auto& x:diakok) cout<<x;

    cout<<"**********************************************************"<<endl;

    cout<<"Felveteli teszt, A) konstruktor"<<endl;
    Felveteli flv(2);
    flv.beiratkozas(d1);
    Diak dd1("Kis", "Diak", 9.56);
    Diak dd2("Kisebb", "Diakocska", 7.916);
    Diak dd3("Kicsike", "Diak", 5.66);

    flv.beiratkozas(dd1);
    flv.beiratkozas(dd2);
    flv.beiratkozas(dd3);

    flv.rendezesABC();
    flv.kiiratas(cout);
    cout<<"*******"<<endl;
    //flv.rendezesAtlag();
    flv.bejutottak(cout);

    cout<<"Felveteli teszt, B) konstruktor"<<endl;
    Felveteli flvfile("diakok.txt");
    flvfile.bejutottak(cout);
    ofstream output("output.txt");
    flvfile.bejutottak(output);

    return 0;
}
