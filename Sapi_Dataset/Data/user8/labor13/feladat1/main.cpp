#include <iostream>
#include "Strangecompare.h"
#include <fstream>
#include <set>
using namespace std;

int main()
{
    cout << "<<<STRANGER THINGS>>>" << endl;
    ifstream f("input.txt");
    string line;
    string sc;
    getline(f,sc);
    //StrangeCompare sc(line);
    set<string, StrangeCompare> strangeSet(sc);
    cout<<"++++++++++++++++++++"<<endl;
    while(getline(f, line)){
        strangeSet.insert(line);
    }

    for (auto& x: strangeSet)
    {
        cout<<x<<endl;
    }


    return 0;
}
