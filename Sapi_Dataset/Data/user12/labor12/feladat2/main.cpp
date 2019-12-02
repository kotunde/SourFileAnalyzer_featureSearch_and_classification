#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int f=0,i;
    char words[5];
    char u[121][5];
    char szo[10];
    words[0]='A';
    words[1]='E';
    words[2]='K';
    words[3]='M';
    words[4]='T';
    do
    {
        cout << f << " ";
        for(i=0; i<5; ++i){
        cout << words[i];
        u[f][i]=words[i];
        }
        ++f;
        cout << endl;
    }
    while(next_permutation(words, words+5));

    cin >> szo;
    int j, k=0;
    for(j=0; j<120; ++j){
        for(i=0; i<5; ++i){
            if(szo[i]==u[j][i]){
               ++k;}
        }
        if (k==5){
            cout << "A szo a " << j <<"-ik helyen van!";
        }
        k=0;
    }
    return 0;
}
