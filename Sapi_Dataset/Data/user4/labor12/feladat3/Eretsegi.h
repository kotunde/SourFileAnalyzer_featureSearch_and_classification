#ifndef ERETSEGI_H_INCLUDED
#define ERETSEGI_H_INCLUDED
#include <iostream>
#include <map>
#include <utility>
#include<fstream>
#include<string.h>
#include<sstream>
#include"Diak.h"

using namespace std;

class Eretsegi
{
private:
    map<int,Diak>registry;

public:
    Eretsegi(string nevek, string mateks,string magyars,string romans)
    {
        diakok(nevek);
        matek(mateks);
        magyar(magyars);
        roman(romans);
        setAtlagok();
        printEretsegizokSzama();
    }


    void diakok(string filename)
    {
        ifstream ifs(filename);
        string line;
        getline(ifs,line);
        while(line.size()!=0)
        {
            //cout<<line<<endl;
            istringstream iss(line);
            string vnev, knev;
            int id;
            iss >> id >>vnev>>knev;
            Diak d(id,vnev,knev);
            registry.insert({id,d});
            getline(ifs,line);
        }
    }


    void roman(string filename)
    {
        ifstream ifs(filename);
        string line;
        getline(ifs,line);
        while(line.size()!=0)
        {
            //cout<<line<<endl;
            istringstream iss(line);
            int id;
            double rom;
            iss >> id >>rom;
            auto poz = registry.find(id);
            if( poz != registry.end())
            {
                Diak aux=poz->second;
                aux.setRoman(rom);
                (poz->second)=aux;
            }
            getline(ifs,line);
        }
    }



    void magyar(string filename)
    {
        ifstream ifs(filename);
        string line;
        getline(ifs,line);
        while(line.size()!=0)
        {
            //cout<<line<<endl;
            istringstream iss(line);
            int id;
            double magy;
            iss >> id >>magy;
            auto poz = registry.find(id);
            if( poz != registry.end())
            {
                Diak aux=poz->second;
                aux.setMagyar(magy);
                (poz->second)=aux;
            }
            getline(ifs,line);
        }

    }

    void matek(string filename)
    {
        ifstream ifs(filename);
        string line;
        getline(ifs,line);
        while(line.size()!=0)
        {
            //cout<<line<<endl;
            istringstream iss(line);
            int id;
            double mat;
            iss >> id >>mat;
            auto poz = registry.find(id);
            if( poz != registry.end())
            {
                Diak aux=poz->second;
                aux.setMatek(mat);
                (poz->second)=aux;
            }
            getline(ifs,line);
        }

    }

    void setAtlagok() {
        for (auto i : registry){
            Diak diak=i.second;
            diak.setAtlag();
            int id=i.first;
            auto poz = registry.find(id);
            if( poz != registry.end())
            {
                (poz->second)=diak;
            }
        }
    }

    void printMap(){
        for (auto i : registry){
            Diak diak=i.second;
            diak.kiir();

        }
    }

    void printEretsegizokSzama(){
        int sum=0;
        int sum1=0;
        for (auto i : registry){
            Diak diak=i.second;
            if(diak.getAtlag() >= 6){
                sum++;
            }else{
                sum1++;
            }

        }
        cout << "Sikeresen eretsegizo diakok szama: "<<sum<<endl;
        cout << "Sikertelenul eretsegizo diakok szama: "<<sum1<<endl;
    }


};


#endif // ERETSEGI_H_INCLUDED
