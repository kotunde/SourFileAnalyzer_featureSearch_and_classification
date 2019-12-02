#ifndef DIAK_H_INCLUDED
#define DIAK_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
class Diak{
int azonosito ;
string vnev;
string knev;
double matek,roman ,magyar;
public:
    Diak( int,string,string);
    string getVnev()const;
    string getKnev() const;
    int getAzonosito() const;

    void setMatek(double mat);
    void setMagyar(double magy);
    void setRoman(double rom);
    double getMatek();
    double getRoman();
    double getMagyar();
    friend ostream &operator<<(ostream&,Diak &);


};


#endif // DIAK_H_INCLUDED
