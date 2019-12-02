#include <iostream>
#include <stdlib.h>
#include <string>
#include "stringffv.h"

using namespace std;

int main() {
    //fel1

    //cout << (char) 33 << endl;
    string line;
    getline(cin,line);
    while (line!="stop")
    {
        line = capitalizeWords(line);
        cout << line << endl;
        line=code(line);
        cout << "Kodolva: " << line <<endl;
        line=decode(line);
        cout << "Dekodolva:" << line << endl;
        cout << splitText(line) << endl << endl << endl;
        getline(cin, line);
    }
    return 0;
}