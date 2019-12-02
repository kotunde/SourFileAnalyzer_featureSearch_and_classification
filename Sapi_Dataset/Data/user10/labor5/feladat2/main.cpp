#include <iostream>
#include "List.h"
#include <random>
#include <stdexcept>

using namespace std;

int main(){
    cout << "Az oviban megkerdezzuk a gyerekeket a kedvenc szamaikrol.\n";
    List Anna, Bela, Ceci, Dani;///nekik a kedvenc szamai
    cout << "Anna azt mondta, hogy: ";
    long anna_valaszai[5];
    for(unsigned i=0; i<5; ++i)
        cin >> anna_valaszai[i];
    Anna = List(5,anna_valaszai);
    cout << "Belat ismertem s mar tudtam a valaszat: ";
    for(unsigned i=0; i<Anna.size(); ++i){
        cin >> Bela;
    }
    cout << endl;
    cout << "Ceci nagyon gyorsan/magabiztosan mondta a szamokat. (Szerintem halanzsazott, akkor talalhatta ki oket)\n";
    for(unsigned i=0; i<7; ++i)
        Ceci.push_back(rand()%20+1);
    cout << "Csonginak tetszik Ceci, igy utanozza es neki is ugyan azok a kedvenc szamai mint Cecinek.\n";
    List Csongi(Ceci);
    cout << "Ceci egy valogatos kurva es csak a hozza hasonlo sracokat birja igy Csonginak ";
    cout << (Csongi==Ceci?"sikerult":"nem sikerult") << " bevagodnia Cecinel.\n";
    cout << "Dani faszagyerek volt, s visszafele mondta a szamokat (a legutalatosabbtol a kedvencig)\n";
    cout << "Ugyanakkor nem voltak baratok Belaval, szoval amit az egyik szeret a masik nem... ovoda...";
    for(unsigned i=0; i<Bela.size(); ++i)
        Dani.push_front(Bela[i]);
    cout << "Anna cuki csajszi mivel azt mondta, hogy ad egy ****(cukorkat ;) ) azoknak a fiuknak(es nem csak) akik szeretik az o kedvencs szamat.\n";
    unsigned counter=0;
    if(Bela.exists(Anna.back())) ++counter;
    if(Ceci.exists(Anna.back())) ++counter;
    if(Csongi.exists(Anna.back())) ++counter;
    if(Dani.exists(Anna.back())) ++counter;
    cout << "Anna igy kiosztott " << counter << " darab cukorkat.\n";
    cout << "vegul nezzuk meg a gyerekeknek mellyek a kedvenc szamjaik?\n";
    List osszes(Anna+Bela+Ceci+Dani);
    osszes += Csongi; ///Csongit majdnem kihagytuk;
    List osszesitett;
    while(osszes.empty() == false){
        long egyik_szam = osszes.front();
        osszesitett.push_back(egyik_szam);
        osszes.remove(egyik_szam);
    }
    cout << "Az eredmeny:"; while(osszesitett.size()){cout << osszesitett.front();osszesitett.pop_front();}
    cout <<"\nNah nektek fellottek a fizsit ovisok, itt az ideje a deli alvasnak, sziasztoooooooook! (kis retard gorcsok XD )\n";
    return 0;
}
