#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
#include "StrangeCompare.h"

using namespace std;

int main()
{
    ifstream ifs("b.txt"); string line;
    if (!ifs){cerr << "Fajl megnyitasi hiba"; return 1;}

    getline(ifs,line);
    set<string,StrangeCompare> nevek(line);

    while (getline(ifs,line)){
        nevek.insert(line);
    }

    for (auto& a: nevek){
        cout << a << endl;
    }

    return 0;
}
