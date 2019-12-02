#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include "alkalmazott.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Manager : public Alkalmazott{
    private:
        vector<Alkalmazott*> beosztottak;
    public:
        Manager(string,string,int,string);
        virtual void print(ostream& os=cout) const;
        void addAlkalmazott(Alkalmazott*);
        void deleteAlkalmazott(Alkalmazott*);
        int beosztottakSzama() const;
};

#endif // MANAGER_H_INCLUDED
