#include <iostream>
#include <cstdio>
#include <utility>
#include <sstream>
#include <map>
#include <cstdlib>
#include <string>

using namespace std;

class Registry
{
    map <string, pair <int, int>> reg;
    unsigned long long int db = 0;
public :

    Registry(const char * be)
    {
        freopen(be,"r",stdin);
        string nev, line;
        int szul, hal;
        while (getline(cin,line))
        {
            hal = 0;
            istringstream ff (line);
            ff>>nev>>szul>>hal;
            if (szul>0 && hal>0)
                db++;
            reg.insert({nev,{szul,hal}});
            if (line.size() == 0)
            {
                while (getline(cin,line))
                {
                    istringstream ff (line);
                    ff>>nev>>hal;
                    szul = 0;
                    if (reg.find(nev)!=reg.end() && !reg.find(nev)->second.second)
                    {
                        reg.find(nev)->second.second = hal;
                        db++;
                    }
                    else
                        reg.insert({nev,{0,hal}});
                    ff.clear();
                }
            }
            ff.clear();
        }
    }
    map <string, pair <int, int>> tart () const
    {
        return reg;
    }
    unsigned long long int getDb () const
    {
        return db;
    }
};


int main()
{
    Registry r ("be.txt");
    map <string, pair <int, int>> par = r.tart();

    for (auto & x  : par)
    {
        if (x.second.first && x.second.second)
        {
            cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<"\n";
        }
    }


    cout<<"\n"<<r.getDb()<<"\n";
    return 0;
}
