#include "Manager.h"

using namespace std;
Manager::Manager(string vNev, string kNev, int szEv, string mkor) : Alkalmazott(vNev, kNev, szEv, mkor){

}
void Manager::addAlkalmazott(Alkalmazott* alk){
    alkalmazottak.insert(alk);
}
void Manager::deleteAlkalmazott(Alkalmazott* alk){
    alkalmazottak.erase(alk);
}
int Manager::beosztottakSzama() const{
    return alkalmazottak.size();
}
void Manager::print(ostream& os) const{
    os<<vezetekNev<<" "<<keresztNev<<" egy alkalmazott(szul:"<<szuletesiEv<<") "<<munkakor<<" munkakorben.\nBeosztottjai pedig:\n";
    for(auto& sit:alkalmazottak) {os<<"\t"; sit->print(os);}
}
