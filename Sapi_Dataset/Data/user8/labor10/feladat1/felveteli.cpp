#include "felveteli.h"

Felveteli::Felveteli(int n) {
    helyekSzama = n;
}

Felveteli::Felveteli(const char* txt) {
    ifstream filestr(txt);
    filestr>>this->helyekSzama;

    Diak d("","",0);
    while(filestr>>d) {
        this->beiratkozas(d);
    }


}
void Felveteli::beiratkozas(Diak d) {
    diakok.push_back(d);
}
void Felveteli::rendezesABC() {
    sort(diakok.begin(), diakok.end(), EntityComparator(1));
}
void Felveteli::rendezesAtlag() {
    sort(diakok.begin(), diakok.end(), EntityComparator(2));
}
void Felveteli::kiiratas(ostream& o) {
    for(auto i: diakok) {
        o<<i;
    }
}
void Felveteli::bejutottak(ostream& o) {

    for(auto i: diakok) {
        if(i.getAtlag() >=5 ) {
            o<<i;
        }
    }
}
