#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <cstdlib>

using namespace std;

double median(vector<double>& );

int main()
{
    vector<double> a;
    try{
        cout<<endl<<"A median:"<<median(a);
        }catch(const domain_error & e){
        cout<<"Exception was domain_error :"<<e.what()<<endl;
        }
    cout<<endl;

    for(int i=0; i<=6; i++)
       a.push_back(i);
        random_shuffle(a.begin(),a.end());
         try{
        cout<<endl<<"A median:"<<median(a);
        }catch(const domain_error & e){
        cout<<"Exception was domain_error :"<<e.what()<<endl;
        }
    cout<<endl;
        for(auto &x:a)
    {
        cout<<x<<" ";
    }
    a.clear();
    for(int i=0; i<=7; i++)
       a.push_back(i);
        random_shuffle(a.begin(),a.end());
         try{
        cout<<endl<<"A median:"<<median(a);
        }catch(const domain_error & e){
        cout<<"Exception was domain_error :"<<e.what()<<endl;
        }
    cout<<endl;
        for(auto &x:a)
    {
        cout<<x<<" ";
    }
    return 0;
}
double median(vector<double>& a)
{
    if(a.size()==0)
    {
        throw domain_error("A halmaz ures");
    }
    if(a.size()%2==1)
    {
        nth_element(a.begin(),a.begin()+a.size()/2,a.end());
        return a[a.size()/2];
    }
    if(a.size()%2==0)
    {
        nth_element(a.begin(),a.begin()+a.size()/2,a.end());
        nth_element(a.begin(),a.begin()+a.size()/2-1,a.end());
        return (a[a.size()/2]+a[a.size()/2-1])/2;

    }
}
