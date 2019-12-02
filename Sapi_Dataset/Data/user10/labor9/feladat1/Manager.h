#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED
#include "Alkalmazott.h"
#include <set>

using namespace std;
class Manager : public Alkalmazott{
private:
    set<Alkalmazott*> alkalmazottak;
public:
    Manager(string, string, int, string);
    void addAlkalmazott(Alkalmazott*);
    void deleteAlkalmazott(Alkalmazott*);
    int beosztottakSzama() const;
    virtual void print(ostream&) const;
};

#endif // MANAGER_H_INCLUDED
