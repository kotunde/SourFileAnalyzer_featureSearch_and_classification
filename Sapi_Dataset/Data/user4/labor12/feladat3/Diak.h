#ifndef DIAK_H_INCLUDED
#define DIAK_H_INCLUDED
#include <iostream>

using namespace std;

class Diak{
private:
    string vNev;
    string kNev;
    int id;
    double roman;
    double magyar;
    double matek;
    double atlag;
public:
    Diak(int id, string vNev, string kNev) {
        this->id = id;
        this->vNev = vNev;
        this->kNev = kNev;
        this->roman = 0;
        this->magyar = 0;
        this->matek = 0;
        this->atlag = 0;
    }

    void setvNev(string vNev) {
        this->vNev = vNev;
    }

    void setkNev(string kNev) {
        this->kNev = kNev;
    }

    void setId(int id) {
        this->id = id;
    }

    void setRoman(double roman) {
        this->roman = roman;
    }

    void setMagyar(double magyar) {
        this->magyar = magyar;
    }

    void setMatek(double matek) {
        this->matek = matek;
    }

    void setAtlag() {
        if (this->magyar >= 5 && this->matek >= 5 && this->roman >= 5) {
            this->atlag = (this->magyar + this->matek + this->roman) / 3;
        }
    }

    string getvNev() {
        return vNev;
    }

    string getkNev() {
        return kNev;
    }

    int getId() {
        return id;
    }

    double getRoman() {
        return roman;
    }

    double getMagyar() {
        return magyar;
    }

    double getMatek() {
        return matek;
    }

    double getAtlag() {
        return atlag;
    }
    void kiir(){
        cout << id << " "<< vNev<<" "<<kNev<<" "<<magyar<<" "<<roman<<" "<<matek<<" "<<atlag<<endl;
    }
};


#endif // DIAK_H_INCLUDED
