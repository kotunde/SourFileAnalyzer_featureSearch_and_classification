#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Szerzo.h"
#include "Konyv.h"


using  namespace std;

int main()
{
    cout << "********************************************************************************************************************************" << endl <<"a) alpont" << endl;
    Szerzo sz1("Koncsard", "Tunde");
    cout << sz1<< endl;

    cout << "********************************************************************************************************************************" << endl <<"b) alpont" << endl;
    Szerzo* sz2=new Szerzo("Koncsard","Tunde");
    cout<<*sz2 << endl;

    cout << "********************************************************************************************************************************" << endl <<"c) alpont" << endl;
    string line;
    vector <Szerzo> v;
    ifstream ifs ("input.txt");
    if (ifs.is_open())
    {
//        while ( getline (fin,line) )
//        {
//            int i=0;
//            string s1,s2;
//            cout  << "sor :"<< line<< endl;
//            int end=1;
//            while (i<line.length())
//            {
//                while(i!=(char)32)
//                {
//                    s1+=line[i];
//                    ++i;
//                }
//                cout << endl;
//                while(i<line.length())
//                {
//                    s2+=line[i];
//                    ++i;
//                }
//            }
//            Szerzo temp(s2,s1);
//            v.push_back(temp);
//        }
        string knev;
        while(ifs>>knev)
        {
            string vnev;
            ifs >>vnev;
            Szerzo temp(vnev,knev);
            v.push_back(temp);
        }
        ifs.close();
    }
    else cout << "Input file error";
    int i=0;
    for (auto& it:v)
    {
        cout << i <<". " << it << endl;
        i++;
    }
    cout << "********************************************************************************************************************************" << endl <<"d) alpont" << endl;
    v.push_back(sz1);
    v.push_back(*sz2);
    for (auto& it:v)
    {
        cout  << it << endl;
    }
    cout << "********************************************************************************************************************************" << endl <<"masodik feladat:" << endl;
    vector <Konyv> Konyvek;
    Konyv k1("Vuk",1920);
    Szerzo sz3("Fekete","Istvan");
    k1.addSzero(sz3);
    Konyv k2("Monte-Cristo grofra", 1850);
    Szerzo sz4("Alexandre","Dumas");
    k2.addSzero(sz4);
    Konyv k3("Az aranyember",1900);
    Szerzo sz5("Jokai","Mor");
    k3.addSzero(sz5);
    Konyvek.push_back(k1);
    Konyvek.push_back(k2);
    Konyvek.push_back(k3);

    cout << "Konyvek amelyek 1989 utan jelentek meg es egyetlen szerzojuk van:" << endl;
    //if(k1.getKiadasi_ev()>1989) {cout << "igen";} else { cout << "nem";};
    for (auto& it: Konyvek)
    {
        if (it.getKiadasi_ev()>1989 && it.getSzerzoSzam()==1)
        {
            cout << it << endl;
        }
    }

    return 0;
}