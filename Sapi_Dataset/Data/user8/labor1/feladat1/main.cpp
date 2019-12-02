#include <iostream>
#include <string>
#include "func.h"

using namespace std;

int main()
{
    cout<<"LAB 1"<<endl<<endl;

    cout<<"0-tol 127-ig a szamok bitjeinek szama:"<<endl;
    for(int i=0; i<= 127; i++){
        cout<<countBits(i)<<"\t";
    }

    cout<<endl;
    cout<<"\nBitbeallitas:"<<endl;
    int bit=0;
    setBit(bit, 0);
    cout<<bit<<"  ";
    setBit(bit, 3);
    cout<<bit<<endl;

    cout<<endl;
    cout<<"Tomb atlaga: ";
    double array[] = {1.23,2,3.45,2.5};
    int n=3;
    cout<<mean(array, n)<<endl;

    cout<<"Szoras: ";
    cout<<stddev(array, n)<<endl;

    cout<<endl;
    cout<<"Mondat nagybetusitese. A tesztmondatod?"<<endl;
    // single line "cin" //
    std::string test;
    std::getline(std::cin, test);
    //                   //

    //std::string test = "Ez eGY mOndat.";
    cout<<capitalizeWords(test)<<endl;
    std::string _text = code(test);

    cout<<endl;
    cout<<"Elkodolt szovege a beutott mondatnak: "<<_text<<endl;
    cout<<"A visszakodolt szoveg: "<<decode(_text)<<endl;


    cout<<endl;
    cout<<"A szavak szama: "<<splitText(_text)<<endl;

    cout<<endl;
    cout<<"Vektor a szavakkal: "<<endl;
    vector<string> splitCSV = splitCSVLine(_text);
    for(auto& x: splitCSV ){
        cout<<x<<"\t";
    }
    //cout<<splitCSV.size();

    cout<<endl;
    return 0;
}
