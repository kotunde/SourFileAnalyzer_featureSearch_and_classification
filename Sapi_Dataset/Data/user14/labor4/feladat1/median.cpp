//
// Created by tuni on 10/15/18.
//

#include "median.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>

using namespace std;

double median(vector<double> myvector) throw (domain_error)
{
    if (myvector.size()==0)
    {
        throw domain_error ("Ures tomb");
    }
    else if (myvector.size()%2==1)
    {
        nth_element(myvector.begin(),myvector.begin()+(myvector.size()/2),myvector.end());
        cout<< "Szetvalasztas utan:";
        for (auto& it:myvector)
        {
            cout << it << " ";
        }
        cout << endl;
        return myvector[myvector.size()/2];
    }
    else
    {
        nth_element(myvector.begin(),myvector.begin()+(myvector.size()/2)-1,myvector.end());
        sort(myvector.begin()+myvector.size()/2,myvector.end());
        cout<< "Szetvalasztas es rendezes utan";
        for (auto& it:myvector)
        {
            cout << it << " ";
        }
        cout<< endl;
        return (myvector[myvector.size()/2-1]+myvector[myvector.size()/2])/2;
    }

}