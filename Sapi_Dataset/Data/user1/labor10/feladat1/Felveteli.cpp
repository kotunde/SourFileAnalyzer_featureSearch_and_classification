#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Felveteli.h"
#include "Diak.h"

Felveteli::Felveteli(int helyekSzama){
    this->helyekSzama = helyekSzama;
}

void Felveteli::beiratkozas(Diak d){
    this->diakok.push_back(d);
}

void Felveteli::rendezesABC(){
    sort(this->diakok.begin(),this->diakok.end());
}

bool atlag (const Diak& d1, const Diak& d2){
    return d1.getAtlag() > d2.getAtlag();
}

void Felveteli::rendezesAtlag(){
    sort(this->diakok.begin(),this->diakok.end(),atlag);
}

void Felveteli::kiiratas(ostream& os){
    for (unsigned int i = 0; i < this->diakok.size(); ++i){
        os << this->diakok[i].getVnev() << " " << this->diakok[i].getKnev() << " " << this->diakok[i].getAtlag() << endl;
    }
}

void Felveteli::bejutottak(ostream& os){
    for (unsigned int i = 0; i < this->diakok.size(); ++i){
        if (this->diakok[i].getAtlag() >= 5){
            os << this->diakok[i].getVnev() << " " << this->diakok[i].getKnev() << " " << this->diakok[i].getAtlag() << endl;
        }
    }
}

