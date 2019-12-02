#include <iostream>
#include <string>
using namespace std;
#include "Diak.h"

Diak::Diak(int az,string v,string k)
{
    this->azonosito=az;
    this->knev=k;
    this->vnev=v;

}
string Diak::getVnev()const
{
    return this->vnev;
}
string Diak::getKnev() const
{
    return this->knev;
}
int Diak::getAzonosito() const
{
    return this->azonosito;
}
void Diak::setMatek( double j)
{
    this->matek=j;
}
void Diak::setMagyar(double j)
{
    this->magyar=j;
}
void Diak::setRoman(double j)
{
    this->roman=j;
}
double Diak::getMagyar()
{
    return this->magyar;
}
double Diak::getMatek()
{
    return this->matek;
}
double Diak::getRoman()
{
    return this->roman;
}
ostream &operator<<(ostream& os,Diak & d)
{
    os<<d.vnev<<" "<<d.knev<<endl;
    return os;
}
