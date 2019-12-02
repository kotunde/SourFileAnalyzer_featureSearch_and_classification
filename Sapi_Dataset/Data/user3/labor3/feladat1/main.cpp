#include <cstdlib>
#include <iostream>
#include "PontHalmaz.h"

using namespace std;

int main(int argc, char** argv) {
     int n = 2;
     cout<<"Pontok\t\tMinTav\t\tMaxTav\t\t#tavolsagok\t\t#kulonbozotavolsagok"<<endl;
     for( int i= 0; i<12; ++i ){
         PontHalmaz ph( n );
         cout<<n<<"\t\t"<<ph.minTavolsag()<<"\t\t"<<ph.maxTavolsag()<<"\t\t";
         cout<<ph.tavolsagokSzama()<<"\t\t\t"<<ph.kulonbozoTavolsagokSzama()<<endl;
         n = n << 1;
     }
     cout<<endl;
/*
     n=10;
     PontHalmaz ph2(n);
     cout<<"Pontok: \n";
     ph2.printPontok(); cout<<endl;
     ph2.rendezPontokX();
     cout<<"Rendezes X szerint:\n";
     ph2.printPontok(); cout<<endl;
     ph2.rendezPontokY();
     cout<<"Rendezes Y szerint:\n";
     ph2.printPontok(); cout<<endl;
*/
     return 0;
}
