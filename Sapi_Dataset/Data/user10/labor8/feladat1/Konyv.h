#ifndef KONYV_H
#define KONYV_H

#include <string>
#include "Szerzo.h"
#include <vector>
#include <stdexcept>

class Konyv{
private:
    std::string cim;
    std::vector<Szerzo> szerzok;
    int kiadasi_ev;
public:
    Konyv(std::string,int);
    std::string cim_get() const;
    void cim_set(std::string);
    int kiadasi_ev_get() const;
    void kiadasi_ev_set(int);
    void add_Szerzo(const Szerzo&);
    friend std::ostream& operator<<(std::ostream&, const Konyv&);
    unsigned szerzok_szama() const;
    Szerzo operator[](unsigned) const;
    friend bool operator<(const Konyv&, const Konyv&);
};

#endif // KONYV_H_INCLUDED
