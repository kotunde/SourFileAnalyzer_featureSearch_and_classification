#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>

using namespace std;

double median(vector<double>& elemek) throw (domain_error){
    int n=elemek.size();
    if(n==0){
        throw domain_error("Ures halmaz!\n");
    }
    if(n%2==0){
        nth_element(elemek.begin(),elemek.begin()+n/2-1,elemek.end());
        double x1=elemek[n/2-1];
        nth_element(elemek.begin(),elemek.begin()+n/2,elemek.end());
        double x2=elemek[n/2];
        return (x1+x2)/2;
    }
    else{
        nth_element(elemek.begin(),elemek.begin()+n/2,elemek.end());
        return elemek[n/2];
    }
}

int main()
{
    vector<double> elemek;

    //**************************************************
    //ures halmaz
    cout<<"1. eset:\n";
    try{
        cout<<"Median: "<<median(elemek)<<"\n\n";
    }
    catch(exception &err){
        cout<<err.what()<<endl;
    }

    //**************************************************
    //paratlan elmek
    cout<<"2. eset:\n";
    int i;
    for (i=1; i<10; i++){
        elemek.push_back(i);
    }
    if(elemek.size()>1){
        random_shuffle(elemek.begin(), elemek.end());
    }
    for (auto& e: elemek){
        cout<<e<<" ";
    }
    try{
        cout<<"\nMedian: "<<median(elemek)<<"\n\n";
    }
    catch(exception &err){
        cout<<err.what()<<endl;
    }

    //*************************************************
    //paros elemek
    cout<<"3. eset:\n";
    elemek.push_back(i+1);
    if(elemek.size()>1){
        random_shuffle(elemek.begin(), elemek.end());
    }
    for (auto& e: elemek){
        cout<<e<<" ";
    }
    try{
        cout<<"\nMedian: "<<median(elemek)<<"\n\n";
    }
    catch(exception &err){
        cout<<err.what()<<endl;
    }
    return 0;
}
