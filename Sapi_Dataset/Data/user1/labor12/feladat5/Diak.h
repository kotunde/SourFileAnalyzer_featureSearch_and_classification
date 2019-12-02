#ifndef DIAK_H_INCLUDED
#define DIAK_H_INCLUDED
#include <string>

using namespace std;

class Diak{
private:
    string vnev, knev;
    double magyar, roman, matek;
public:
    Diak(string,string);

    string getVnev() const;
    string getKnev() const;
    double getAtlag() const;
    double getMagyar() const;
    double getMatek() const;
    double getRoman() const;

    void setMagyar(double);
    void setRoman(double);
    void setMatek(double);

    friend ostream& operator<<(ostream&, Diak&);
};

#endif // DIAK_H_INCLUDED
