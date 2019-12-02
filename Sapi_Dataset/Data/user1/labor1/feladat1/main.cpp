#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

int main()
{

    /*for (int i = 0; i < 128; ++i){
        cout << i << ": " << countBits(i) << endl;
    }

    int i = 1;
    cout << setBit(i,2);*/

    string s;
    getline(cin,s);
    cout << splitText(s);
    return 0;
}
