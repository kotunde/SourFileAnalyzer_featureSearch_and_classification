#include "functions.h"
#include "Pont.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

bool negyzet_e(Pont a, Pont b, Pont c, Pont d){
    if (egyenlo(a,b) || egyenlo(a,c) || egyenlo(a,d) || egyenlo(b,c) || egyenlo(b,d) || egyenlo(c,d)){return false;}

    int tavolsagok[6];
    tavolsagok[0] = tavolsag(a,b); tavolsagok[1] = tavolsag(a,c); tavolsagok[2] = tavolsag(a,d);
    tavolsagok[3] = tavolsag(b,c); tavolsagok[4] = tavolsag(b,d); tavolsagok[5] = tavolsag(c,d);

    for (int i = 0; i < 6; ++i){
        for (int j = 0; j < 6; ++j){
            if (tavolsagok[i] < tavolsagok[j]){
                int cs = tavolsagok[i];
                tavolsagok[i] = tavolsagok[j];
                tavolsagok[j] = cs;
            }
        }
    }

    if ((tavolsagok[0] == tavolsagok[3]) && (tavolsagok[4] == tavolsagok[5])){return true;}
    else {return false;}
}

bool egyenlo(Pont a, Pont b){

if (a.getX() == b.getX() && a.getY() == b.getY()) {return true;}

return false;

}

int tavolsag (Pont a, Pont b){
    int x1 = a.getX(); int y1 = a.getY();
    int x2 = b.getX(); int y2 = b.getY();
    int t = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
    return t;
}

vector<Pont> legkozelebbi(vector<Pont> a, int n){
    vector<Pont> lk;
    int min_tavolsag = INT_MAX;
    for (int i = 0; i < n-1; ++i)
    {
        for (int j = i+1; j < n; ++j){
            int t = tavolsag(a[i],a[j]);
            if (t < min_tavolsag){
                min_tavolsag = t;
                lk.clear();
                lk.push_back(a[i]); lk.push_back(a[j]);
            }
        }
    }
    return lk;
}

/*vector<Pont> legkozelebbi_divide(vector<Pont> a, int n){
    sort(a,a+n,compareX);
    Pont bal[n/2 + 1], jobb[n/2 - 1];
    int b = 0, j = 0;
    for (int i = 0; i < n; ++i){
        if (i < n/2 + 1){bal[b++] = a[i];}
        else {jobb[j++] = a[i];}
    }
*/

vector<Pont> legtavolabbi(vector<Pont> a, int n){
    vector<Pont> lt;
    int max_tavolsag = 0;
    for (int i = 0; i < n-1; ++i)
    {
        for (int j = i+1; j < n; ++j){
            int t = tavolsag(a[i],a[j]);
            if (t > max_tavolsag){
                max_tavolsag = t;
                lt.clear();
                lt.push_back(a[i]); lt.push_back(a[j]);
            }
        }
    }
    return lt;
}

bool compareX(Pont a, Pont b){return a.getX() < b.getX();}
bool compareY(Pont a, Pont b){return a.getY() < b.getY();}

vector<Pont> legtavolabbi_tiz(vector<Pont> a, int n){
    vector<Pont> lt; Pont origo(0,0);
    for (int i = 0; i < 10; ++i){
        lt.push_back(a[i]);
    }
    for (int i = 10; i < n; ++i){
        int tav = tavolsag(origo,a[i]);
        for (int j = 0; j < 10; ++j){
            if (tav > tavolsag(origo,lt[j])){
                lt[j] = a[i]; break;
            }
        }
    }

    return lt;
}


bool operator== ( const Pont &p1, const Pont &p2)
{
        return ((p1.getX() == p2.getX() && (p1.getY() && p2.getY())));
}
