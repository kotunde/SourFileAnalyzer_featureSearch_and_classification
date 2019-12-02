#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <stdexcept>

using namespace std;

void print(vector<double>);
double median(vector<double>) throw (domain_error);
int main()
{
    vector<double> v;
    for (int i = 0; i < 10; ++i){
        int x = rand() % 10;
        v.push_back(x);
    }

    print(v);

    nth_element(v.begin(),v.begin() + 5,v.end());
    print(v);

    cout << median(v);

    return 0;
}

double median(vector<double> v) throw (domain_error){
    int n = v.size(); double median = 0;
    if (n == 0){
        throw domain_error("Ures tomb");
    }

    if (n % 2 == 0){
        median = (v[n/2] + v[n/2 - 1]) / 2;
    }
    else {median = v[n/2];}
    return median;
}

void print(vector<double> v){
    for (unsigned int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}
