#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
Manager::Manager(string vezn,string kern,int szd,string kor):
    Alkalmazott(vezn,kern,szd,kor)
{
}
void Manager::addAlkalmazott(Alkalmazott * a)
{
    beosztottak.push_back(a);
}
void Manager::deleteAlkalmazott(Alkalmazott * a)
{
    auto temp=find(beosztottak.begin(),beosztottak.end(),a);
    if(temp!=beosztottak.end())
    {
        beosztottak.erase(temp);
    }
}
int Manager::beosztottakSzama()const
{
    return beosztottak.size();
}
void Manager::print(ostream & os)const
{
    os<<vezetekNev<<","<<keresztNev<<","<<szuletesiEv<<","<<munka<<","<<beosztottakSzama();

}
