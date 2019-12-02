#include <iostream>
#include "Szerzo.h"
#include <vector>
#include <fstream>
#include "Konyv.h"
#include <string>

using namespace std;

int main(){
    ///Elso feladat
    Szerzo Me_Myself_And_I("Kezdi","Ors-Sebestyen");
    cout << Me_Myself_And_I << endl<<endl;
    Szerzo* dinamikus_Ors = new Szerzo("Kezdi","Ors-Sebestyen");
    cout << *dinamikus_Ors << endl<<endl;
    ifstream fin("szerzok.txt");
    vector<Szerzo> szerzok;
    if(fin){
        string tmp_knev,tmp_vnev;
        while(fin >> tmp_vnev >> tmp_knev){ szerzok.push_back(Szerzo(tmp_vnev,tmp_knev)); }
        fin.close();
    }else{ cout << "A szerzoket nem tudtam beolvasni a szerzok.txt nevu fajlbol\n";}
    for(auto& sz:szerzok){ cout << sz << endl; }
    cout<<endl;
    szerzok.push_back(Me_Myself_And_I);
    szerzok.push_back(*dinamikus_Ors);
    for(auto& sz:szerzok){ cout << sz << endl; }
    cout<<endl;
    ///Masodik feladat
    vector<Konyv> konyvtar;
    Konyv* bookbuilder;
    bookbuilder = new  Konyv("Poloskainvazio",2018);
    bookbuilder->add_Szerzo( Me_Myself_And_I );
    konyvtar.push_back(*bookbuilder);
    bookbuilder = new  Konyv("Te is fiam, Brutus!",-61);
    bookbuilder->add_Szerzo(Szerzo("Caius Iulius", "Caesar"));
    konyvtar.push_back(*bookbuilder);
    bookbuilder = new  Konyv("Alea iacta est, avagy a vizsga meg van irva",-62);
    bookbuilder->add_Szerzo(Szerzo("Caius Iulius", "Caesar"));
    bookbuilder->add_Szerzo( Me_Myself_And_I );
    konyvtar.push_back(*bookbuilder);
    for(auto& konyv:konyvtar)
        if(konyv.kiadasi_ev_get()>1989 and konyv.szerzok_szama()==1) cout << konyv << endl;
    return 0;
}
