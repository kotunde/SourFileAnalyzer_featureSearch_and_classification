#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Alkalmazott.h"
using namespace std;
class Manager:public Alkalmazott{
public:
    Manager(string,string,int,string);
    void addAlkalmazott(Alkalmazott *);
    void deleteAlkalmazott(Alkalmazott *);
    int beosztottakSzama()const;
    virtual void print( ostream&) const;
protected:
    vector <Alkalmazott*> beosztottak;
};

#endif // MANAGER_H_INCLUDED
