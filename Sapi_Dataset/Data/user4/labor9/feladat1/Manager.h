#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include <iostream>
#include"Szemely.h"
#include<vector>
#include"Alkalmazott.h"
using namespace std;

class Manager:public Alkalmazott{
private:
    vector<Alkalmazott*>beosztottak;
public:
    Manager(string vezetekNev,string keresztNev,int szuletesiEv,string munkakor);
    void addAlkalmazott(Alkalmazott*);
    void deleteAlkalmazott(Alkalmazott*);
    int beosztottakSzama();
    virtual void print(ostream& out)const;
};

#endif // MANAGER_H_INCLUDED
