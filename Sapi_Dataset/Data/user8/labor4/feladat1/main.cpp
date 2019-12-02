#include <iostream>
#include "median.h"
#include <vector>
#include <stdexcept>

using namespace std;

int main()
{
    vector<double> tombpros {1, 2, 5, 4, 3, 1, 4, 3, 4, 4, 3, 5}; // 12 db
    vector<double> tombpratlan {1, 2, 5, 4, 3, 1, 4, 3, 3, 4, 3, 5, 1}; // 13 db
    vector<double> tombures {}; // ures

    cout<<"Ures tomb eseten:"<<endl;
    try{
        median(tombures);
    }catch(domain_error& e){
        cout<<e.what()<<endl;
    }

    cout<<"Paratlan szamu tomb eseten:" <<endl;
    cout<<"\tEredeti:"<<endl;
    print(tombpratlan);

    try{
        cout<<"\tA szam: "<<median(tombpratlan);
    }catch(domain_error& e){
        cout<<e.what();
    }

    cout<<"\n\tA fuggvenyhivas utan:"<<endl;
    print(tombpratlan);

    cout<<"  *  *  *  *  *   ^   *  *  *  *  *"<<endl;

    cout<<"\nParos szamu tomb eseten:" <<endl;
    cout<<"\tEredeti:"<<endl;
    print(tombpros);

    try{
    cout<<"\tA szam: "<<median(tombpros);
    }catch(domain_error e){
        cout<<e.what();
    }

    cout<<"\n\tA fuggvenyhivas utan:"<<endl;
    print(tombpros);
    cout<<"  *  *  *  *   ^  ^   *  *  *  * "<<endl;

    return 0;
}
