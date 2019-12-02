#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include "employee.h"
#include <vector>
#include <algorithm>

class Manager:public Alkalmazott{

private:
    vector <Alkalmazott*> beosztottak;

public:
    Manager(string, string, int, string);
    void addAlkalmazott(Alkalmazott* );
    void deleteAlkalmazott(Alkalmazott*);
    int beosztottakSzama() const;
    void virtual print(ostream&) const;
};

#endif // MANAGER_H_INCLUDED
