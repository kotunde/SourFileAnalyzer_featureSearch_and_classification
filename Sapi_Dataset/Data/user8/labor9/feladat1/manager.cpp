#include "manager.h"


Manager::Manager(string a, string b, int c, string d):Alkalmazott(a,b,c,d){};
void Manager::addAlkalmazott(Alkalmazott* a)
{
    this->beosztottak.push_back(a);
}
void Manager::deleteAlkalmazott(Alkalmazott* a)
{
    auto it=std::remove(beosztottak.begin(), beosztottak.end(), a);
    beosztottak.erase(it, beosztottak.end());
}
int Manager::beosztottakSzama() const
{
    return beosztottak.size();
}
void Manager::print(ostream& os) const
{
    os<<vezetekNev<<" "<<keresztNev<<", "<<szuletesiEv<<", "<<munkakor<<", beosztottak szama: "<<this->beosztottakSzama();
}
