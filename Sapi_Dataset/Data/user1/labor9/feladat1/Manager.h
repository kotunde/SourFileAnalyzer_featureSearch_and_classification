#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED
#include <string>
#include <iostream>
#include <vector>
#include "Alkalmazott.h"

using namespace std;

class Manager:public Alkalmazott{
private:
    vector<Alkalmazott*> beosztottak;
public:
    Manager(string,string,int,string);
    void addAlkalmazott(Alkalmazott*);
    void deleteAlkalmazott(Alkalmazott*);
    int beosztottakSzama() const;
    virtual void print(ostream& os = cout) const;
};

#endif // MANAGER_H_INCLUDED
