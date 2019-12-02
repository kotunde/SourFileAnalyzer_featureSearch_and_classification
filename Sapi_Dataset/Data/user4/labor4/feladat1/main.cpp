#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <fstream>

using namespace std;

void print(const vector<double>&);
double median( vector<double>& );


int main()
{
    int n;
    ifstream fin("be.txt");
    if( !fin )
    {
        cout<<"Fajl hiba"<<endl;
        return 404;
    }
    cout << "Ures tomb:"<<endl;
    vector<double> tomb1;
    print(tomb1);
    try
    {
        cout<<"Median: "<<median(tomb1)<<endl;
    }
    catch(domain_error)
    {
        cout << "ures halmaz"<<endl;;
    }
    print(tomb1);

    cout << "Paros elemszamu tomb:" << endl;
    fin>>n;
    vector<double> tomb2;
    for (int i=0; i<n; i++)
    {
        double e;
        fin>>e;
        tomb2.push_back(e);
    }
    print(tomb2);
    try
    {
        cout<<"Median: "<<median(tomb2)<<endl;
    }
    catch(domain_error)
    {
        throw "ures halmaz";
    }
    print(tomb2);

    cout << "Paratlan elemszamu tomb:" << endl;
    double e;
    fin>>e;
    tomb2.push_back(e);
    random_shuffle (tomb2.begin(), tomb2.end());
    print(tomb2);
    try
    {
        cout<<"Median: "<<median(tomb2)<<endl;
    }
    catch(domain_error)
    {
        throw "ures halmaz";
    }
    print(tomb2);


    return 0;
}


void print(const vector<double>& v)
{
    for( auto& e: v)
    {
        cout<<e<<" ";
    }
    cout<<endl;
}

double median( vector<double>& tomb)
{
    int n = tomb.size();
    if (n==0)
    {
        throw domain_error("ures halmaz");
    }

    if (n%2==1)
    {
        nth_element(tomb.begin(), tomb.begin()+n/2, tomb.end());
        return tomb[n/2];
    }
    else
    {
        nth_element(tomb.begin(), tomb.begin()+(n/2)-1, tomb.end());
        int a=tomb[(n/2)-1];
        nth_element(tomb.begin(), tomb.begin()+(n/2), tomb.end());
        double median=(a+tomb[n/2])/2;
        return median;
    }

}
