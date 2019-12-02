#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
double madian(vector<double>)  throw (domain_error);
int main()
{
    ifstream fin;
    fin.open("be.txt");
    vector<double> a;
    int i,n;
    double x;
    fin >> n;
    for(i=0; i<n; ++i){
        fin >>x;
        a.push_back(x);
    }
    cout << "Madian: " << madian(a);
    return 0;
}
double madian(vector<double> a) throw (domain_error){
    if(a.size()==0){
        throw domain_error("ures tomb");
    }
 int i, j, v;
   for (i = 0; i < a.size(); i++)
    for (j = 0; j < a.size(); j++)
        if (a[j] > a[j+1]){
        v=a[j]; a[j]=a[j+1]; a[j+1]=v;
        }
     if(a.size()%2!=0){
        return a[a.size()/2+1];
     }
     else{

        return (double)(a[a.size()/2]+a[(a.size()/2)+1])/2;
     }
}

