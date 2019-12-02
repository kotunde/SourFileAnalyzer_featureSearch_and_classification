#include "Felveteli.h"
#include <algorithm>
#include <fstream>

Felveteli::Felveteli(int helyekSzama){
    this->helyekSzama=helyekSzama;
}

Felveteli::Felveteli(const char* filename){
    ifstream fin;
    fin.open(filename);
    if(!fin){
        cout<<"file error\n";
        exit(0);
    }
    fin>>this->helyekSzama;
    Diak diak;
    while(fin>>diak){
        this->diakok.push_back(diak);
    }
    fin.close();
}

void Felveteli::beiratkozas(Diak diak){
    this->diakok.push_back(diak);
}

void Felveteli::rendezesABC(){
    sort(this->diakok.begin(), this->diakok.end());
}

struct Atlagok{
    bool operator()(Diak& i, Diak& j){
        return i.getAtlag()>j.getAtlag();
    }
} myobject;

void Felveteli::rendezesAtlag(){
    sort(this->diakok.begin(), this->diakok.end(), myobject);
}

void Felveteli::kiiratas(ostream& os){
    for(int i=0; i<this->diakok.size(); i++){
        os<<this->diakok[i]<<endl;
    }
}

void Felveteli::bejutottak(ostream& os){
    this->rendezesAtlag();
    for(int i=0; i<this->helyekSzama; i++){
        os<<this->diakok[i]<<endl;
    }
}
