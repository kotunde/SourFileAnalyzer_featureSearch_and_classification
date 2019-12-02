#ifndef DIAK_H_INCLUDED
#define DIAK_H_INCLUDED
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
class Diak{
private:
    string vnev;
    string knev;
    double atlag;
public:
    Diak(string,string,double);
    double getAtlag()const;
    string getVnev()const;
    string getKnev()const;
    friend ostream & operator<<(ostream& out, const Diak& a);
    friend istream & operator>>(istream& in, Diak& a);
    friend bool operator<( const Diak& a, const Diak& b);
};

class Comparator{
public:
    bool operator()(const Diak& a,const Diak& b){
        return a.getAtlag() > b.getAtlag();
    }
};


#endif
