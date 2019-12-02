#include <cstdlib>
#include <iostream>
#include "PontHalmaz.h"

using namespace std;

int main(int argc, char** argv)
{
    int n = 2;
    cout<<"Pontok\tMinTav\tMaxTav\t#tavolsagok\t#kulonbozotavolsagok"<<endl;

    for( int i= 0; i<12; ++i ){
        PontHalmaz ph( n );
        cout<<n<<"\t\t"<<ph.minTavolsag()<<"\t\t"<<ph.maxTavolsag()<<"\t\t";
        cout<<ph.tavolsagokSzama()<<"\t\t\t"<<ph.kulonbozoTavolsagokSzama()<<endl;
        n = n << 1;
    }

//    PontHalmaz pontHalmaz(10);
//    pontHalmaz.printPontok();
//    cout<< endl;
//    pontHalmaz.printTavolsagok();
//    cout<< endl;
//    pontHalmaz.rendezPontokX();
//    pontHalmaz.printPontok();
//    cout<<endl;
//    pontHalmaz.rendezPontokY();
//    pontHalmaz.printPontok();
//    cout<<endl;
//    pontHalmaz.rendezTavolsagok();
//    pontHalmaz.printTavolsagok();
//    cout<<endl;
//    cout << pontHalmaz.kulonbozoTavolsagokSzama();

    return 0;
}