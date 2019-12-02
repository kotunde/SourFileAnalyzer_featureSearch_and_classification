#ifndef DIAK_H_INCLUDED
#define DIAK_H_INCLUDED
#include <iostream>
using namespace std;

class Diak
{
private:
    string vnev;
    string knev;
    double atlag;


public:
    Diak(string, string, double);
    double getAtlag() const;
    string getVnev() const;
    string getKnev() const;

    friend ostream& operator<<(ostream&, Diak&);
    friend istream& operator>>(istream&, Diak&);

    friend bool operator<(const Diak&, const Diak&);
};

#endif // DIAK_H_INCLUDED
