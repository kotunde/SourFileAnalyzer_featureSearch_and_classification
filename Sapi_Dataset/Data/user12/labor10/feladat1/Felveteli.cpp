#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Diak.h"
#include "Felveteli.h"

Felveteli::Felveteli(int a){
helyekSzama = a;
}

Felveteli::Felveteli(const char* filename){
ifstream fin;
fin.open(filename);
fin >> helyekSzama;
for(;;){
    Diak d("","",-5);
    fin >> d;
    if(d.getAtlag() == -5){
        break;
    }
    diakok.push_back(d);
}
}

void Felveteli::Beiratkozas(Diak a){
diakok.push_back(a);
}

void Felveteli::RendezesABC(){
sort(diakok.begin(), diakok.end());
}

void Felveteli::RendezesAtlag(){
Comparator a;
sort(diakok.begin(), diakok.end(), a);
}

void Felveteli::kiiratas(ostream& out){
int i;
for(i=0; i<diakok.size(); ++i){
    out << diakok[i] << endl;
}
}

void Felveteli::bejutottak(ostream& out){
int i;
this->RendezesAtlag();
for(i=0; i<diakok.size(); ++i){
    if(diakok[i].getAtlag() > 5 && i < helyekSzama){
        out << diakok[i] << endl;
    }
}
}





