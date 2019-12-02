#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include "Feldolgozas.h"

using namespace std;

Feldolgozas::Feldolgozas() {}

void Feldolgozas::beolvasDiakok(string f)
{
    string line;
    ifstream file(f);

    if (!file)
    {
        cerr << "Fajl megnyitasi hiba" << endl;
    }

    while (getline(file,line))
    {
        double azonosito;
        string vnev,knev;
        istringstream iss(line);
        iss >> azonosito >> vnev >> knev;

        diakok.insert(make_pair(azonosito,Diak(vnev,knev)));
    }
}

void Feldolgozas::beolvasJegyek(string magyar, string matek, string roman)
{
    string line;
    double azonosito, jegy;
    ifstream file;

    //magyar
    file.open(magyar);
    if (!file)
    {
        cerr << "Fajl megnyitasi hiba" << endl;
    }

    while (file >> azonosito >> jegy)
    {
        diakok.find(azonosito)->second.setMagyar(jegy);
    }
    file.close();

    //matek
    file.open(matek);
    if (!file)
    {
        cerr << "Fajl megnyitasi hiba" << endl;
    }

    while (file >> azonosito >> jegy)
    {
        diakok.find(azonosito)->second.setMatek(jegy);
    }
    file.close();

    //roman
    file.open(roman);
    if (!file)
    {
        cerr << "Fajl megnyitasi hiba" << endl;
    }

    while (file >> azonosito >> jegy)
    {
        diakok.find(azonosito)->second.setRoman(jegy);
    }
    file.close();
}

void Feldolgozas::print() const
{
    int counter = 0;
    for (auto x : diakok)
    {
        if (x.second.getMagyar() >= 5 && x.second.getMatek() >= 5 && x.second.getRoman() >= 5 && x.second.getAtlag() >= 6){
            counter++;
            //cout << x.first << " " << x.second << "\t" << x.second.getAtlag() << endl;
        }
    }
    cout << "Sikeresen erettsegizett diakok szama: " << counter;
}
