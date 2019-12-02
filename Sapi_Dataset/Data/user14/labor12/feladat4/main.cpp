#include <iostream>
#include <map>
#include <utility>
#include <fstream>
#include <sstream>
///Helyes az eredmeny (csak a teljes adattal rendelkezo embereket irja ki),
///de nem eszleli az ures sort, amikor az uj emberek adatait mar name + dyear
///szerint kell regisztralnia
using namespace std;

int main()
{
    map<string,pair<int,int>> registry;
    ifstream ifs("regiszter0.txt");
    string line;
    map<string, pair<int,int>> :: iterator it;
    if (!ifs.is_open())
    {
        cout << "Input error";
    }
    int sec=0;
    while (getline(ifs,line))
    {
        if (line.empty())
        {
            sec=1;
        }
        else
        {
            istringstream iss(line);
            string name; int byear, dyear=0;
            iss>> name >> byear;
            if (iss)
            {
                iss>>dyear;
            }
            if (registry.find(name)==registry.end() && sec==0)
            {
                cout << sec <<"Nem talalhato " << name << " "<< byear <<" "<< dyear << endl;
                registry.insert({name,{byear,dyear}});
            }
            else if (registry.find(name)==registry.end() && sec==1)
            {
                cout << sec << "Nem talalhato " << name << " "<< dyear <<" "<< byear << endl;
                registry.insert({name,{dyear,byear}});
            }
            else
            {
                it = registry.find(name);
                it->second.second=byear;
            }
        }

    }
    for (auto& x: registry)
    {
        if (x.second.second!=0)
        {
            cout << x.first << " " << x.second.first <<" " << x.second.second;
            cout << endl;
        }
    }
    return 0;
}