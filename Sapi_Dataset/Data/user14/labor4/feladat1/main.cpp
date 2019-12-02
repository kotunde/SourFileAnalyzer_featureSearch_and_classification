#include <iostream>
#include <vector>
#include "median.h"
#include <time.h>

using namespace std;

int main()
{
    int i,n;
    vector<double> myvector;
    srand(time(NULL));
    cin >> n;
    //ures tombre
    try
    {
        cout<< median(myvector)<< endl;
    }catch(const exception& e )
    {
        cout << "Exception " << e.what() <<endl;
    }
    cout << endl;
    //paros szamu tombre
    for (int i=0; i<n*2; ++i)
    {
        myvector.push_back((rand()%100)/10);
    }
    try
    {
        cout<< median(myvector);
    }catch(const exception& e )
    {
        cout << "Exception" << e.what() <<endl;
    }
    cout << endl;
    //paratlan szmu tombre
    myvector.push_back(rand()%100);
    try
    {
        cout<< median(myvector);
    }catch(const exception& e )
    {
        cout << "Exception" << e.what() <<endl;
    }
    return 0;
}