#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
//    cout<<"Adj egy szot: ";
//    string w;
//    cin>>w;
//    while ( next_permutation(w.begin(), w.end()) )
//    {
//        cout<<w<<endl;
//    }
//    cout<<"Nincs tobb...";

    char str[6] {'A','E','K','M','T'};
    int n=5;
    int loopvariable = 0;
    int foundyaa=-1;
    cout<<"Adj egy szot: ";
    char szo[6];
    cin>>szo;

// Az alabb lathato kod a legrosszabb kod trofeat is elnyerhetne, csupan hogy elmondhassam, hogy irtam n^5-es komplexitasu kodot :)

    for(int h=0; h<n; h++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                for(int k=0; k<n; k++) {
                    for(int l=0; l<n; l++) {
                        if(h!=i && i!=j && j!=k && k!=l && l!=i && i!=k && j!=l && h!=j && h != k && h!=l) {
                            loopvariable++;
                            cout<<str[h]<<" "<<str[i]<<" "<<str[j]<<" "<<str[k]<<" "<<str[l]<<endl;
                            //if (str[h] =='M' && str[i] =='A' && str[j]=='T' && str[k] =='E' && str[l]=='K' )
                            if (str[h] ==szo[0] && str[i] ==szo[1] && str[j]==szo[2] && str[k] ==szo[3] && str[l]==szo[4])
                            {
                                foundyaa = loopvariable;

                            }
                        }
                    }
                }
            }
        }
    }

    cout<<"Nincs tobb..."<<endl;
    //cout<<"A MATEK a "<<foundyaa<<"-ik!";
    cout<<"A megadott szo a "<<foundyaa<<"-ik!";
    cout<<loopvariable;

    return 0;
}
