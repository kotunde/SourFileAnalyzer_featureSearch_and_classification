#include "Feldolgozas.h"
#include "Diak.h"
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

void Feldolgozas::olvasNev(string filename)
{
    ifstream ifs(filename);
    int az;
    while(ifs>>az)
    {
        string vnev,knev;
        ifs>>vnev>>knev;
        Diak diak1(az,vnev,knev);
        eretsegi.insert({az,diak1});
    }
    cout<<eretsegi.size()<<endl;

}
void Feldolgozas::olvasMagyar(string filename){
ifstream ifs(filename);
int az;
while(ifs>>az)
{
    double magy;
    ifs>>magy;
    auto pozicio=eretsegi.find(az);
    if(pozicio!=eretsegi.end())
    {
        pozicio->second.setMagyar(magy);
    }
}
}
void Feldolgozas::olvasMatek(string filename)
{
    ifstream ifs(filename);
    int az;
    while(ifs>>az)
    {
        double mat;
        ifs>>mat;
        auto pozicio=eretsegi.find(az);
        if(pozicio!=eretsegi.end())
        {
            pozicio->second.setMatek(mat);
        }
    }
}
void Feldolgozas::olvasRoman(string filename)
{
    ifstream ifs(filename);
    int az;
    while(ifs>>az)
    {
        double rom;
        ifs>>rom;
        auto pozicio=eretsegi.find(az);
        if(pozicio!=eretsegi.end())
        {
            pozicio->second.setRoman(rom);
        }
    }
}
void Feldolgozas::kiiratas()
{
    for (auto &x:eretsegi)
    {
        cout << x.first << " " << x.second.getVnev() << " " << x.second.getKnev() << " " << x.second.getMatek() <<" " << x.second.getMagyar() << " " << x.second.getRoman() << endl;
    }
}

int Feldolgozas::szamitatlag()
{
    int db=0;
    for (auto &x:eretsegi)
    {
        if(x.second.getMatek()>=5 && x.second.getMagyar()>=5 && x.second.getRoman()>=5)
        {
            int atlag=(x.second.getMatek()+x.second.getMagyar()+x.second.getRoman())/3;
            if(atlag>=6)
            {
                db++;
            }
        }
    }
    return db;
}
