#include "Szemely.h"
using namespace std;
Szemely::Szemely(string vNev, string kNev, int szEv){
    vezetekNev = vNev;
    keresztNev = kNev;
    szuletesiEv= szEv;
}
void Szemely::print(ostream& os) const{
    os<<vezetekNev<<" "<<keresztNev<<" egy szemely aki "<<szuletesiEv<<"-ban(/ben) szuletett\n";
}
