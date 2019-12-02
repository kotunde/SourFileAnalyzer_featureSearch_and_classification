#include "Alkalmazott.h"
using namespace std;
Alkalmazott::Alkalmazott(string vNev, string kNev, int szEv, string mkor) : Szemely(vNev, kNev, szEv){
    munkakor = mkor;
}
void Alkalmazott::print(ostream& os) const{
    os<<vezetekNev<<" "<<keresztNev<<" egy alkalmazott(szul:"<<szuletesiEv<<") "<<munkakor<<" munkakorben.\n";
}
