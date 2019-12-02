#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

int main()
{
    cout<<"#1"<<endl;
    for(int i=0; i<=127; i++)
        cout<<i<<": "<<countBits(i)<<endl;

        //*********************************************************
    cout<<"\n#2"<<endl;
    int n=0;
    cout<<setBit(n,0)<<" ->";
    cout<<n<<endl;
    cout<<setBit(n,3)<<" ->";
    cout<<n<<endl;

    //****************************************************************
    cout<<"\n#3"<<endl;
    double *t=new double[5];
    for(int i=0; i<5; i++){
        t[i]=i;
        cout<<t[i]<<" ";
    }
    cout<<" -> atlag: "<<mean(t,5)<<endl;

    //********************************************************************
    cout<<"\n#4\n";
    double a[3]={5,6,10};
    cout<<"5,6,10 -> szoras: "<<stddev(a,3)<<endl;

    //********************************************************************
    cout<<"\n#5\n";
    double b[10]={5,6,10,0,5,7,9,90,1,4};
    for(int i=0; i<10; i++){
        cout<<b[i]<<" ";
    }
    double* c=max2(b,10);
    cout<<"\n2 max elem: "<<c[0]<<", "<<c[1]<<endl;

    //********************************************************************
    cout<<"\n#6\n";
    string text="thIs is a STRing";
    cout<<text<<endl;
    cout<<"capitalize words:  "<<capitalizeWords(text)<<endl;

    //********************************************************************
    cout<<"\n#7\n";
    text="abc - xyz - ABC - XYZ";
    cout<<text<<endl;
    string kod=code(text);
    cout<<"kodolva:  "<<kod<<endl;
    cout<<"dekodolva:  "<<decode(kod)<<endl;

    //********************************************************************
    cout<<"\n#8\n";
    text="alma,  korte!szilva ?? barack. eper.szolo ";
    cout<<text<<"\nszavak: ";
    cout<<"szavak szama:"<<splitText(text)<<endl;

    //********************************************************************
    /*
    cout<<"\n#9\n";
    string line = "Alma , Korte , Szilva ,Eper";
    vector<string> items = splitCSVLine(line);
    for( auto& s: items ){
        cout<< s << endl;
    }
    */
    return 0;
}
