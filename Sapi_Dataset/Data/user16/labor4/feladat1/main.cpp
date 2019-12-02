#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>

using namespace std;

double median(vector<double>& v )
{
    if (!v.size())
    {
        throw domain_error("Nincs egy elem se");
    }
    else if (v.size()%2)
    {
        return v[v.size()/2];
    }
    else
    {
        return (v[v.size()/2]+v[v.size()/2-1])/2;
    }
}

void print (vector <double>& v)
{
    cout<<"elemek: ";
    for (auto & x : v)
        cout<<x<<" ";
    cout<<endl<<endl;
}

int main()
{
    vector <double> v;
    print(v);
    try
    {
        cout<<median(v)<<endl;
    }
    catch (exception &err)
    {
        cout<<err.what()<<endl;
    }
    for (int i = 1 ; i<=10 ; i++)
        v.push_back(i);

    print(v);

    std::random_shuffle (v.begin(), v.end());
    cout<<"Az elemek osszekeverve : ";
    print(v);
    try
    {
        cout<<median(v)<<endl;
    }
    catch (exception &err)
    {
        cout<<err.what()<<endl;
    }

    v.push_back(100);
    std::random_shuffle(v.begin(),v.end());
    print(v);

    try
    {
        cout<<median(v)<<endl;
    }
    catch (exception &err)
    {
        cout<<err.what()<<endl;
    }
}
