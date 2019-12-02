#include <iostream>
#include <vector>
#include <algorithm>
#include "rac.h"
using namespace std;

int main()
{    vector <double> v1;
    v1.push_back(rational(1,2));
    v1.push_back(rational(6,2));
    v1.push_back(rational(3,2));
    for(auto& i:v1){
        cout<<i;
    }
    v1.sort(v1.begin(),v1.end(),seged);


    return 0;
}
bool seged()
