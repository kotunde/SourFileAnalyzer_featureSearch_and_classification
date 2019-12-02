#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include "StrangeCompare.h"
using namespace std;

int main()
{   ifstream fin("be.txt");
    string uj;
    fin>>uj;
    StrangeCompare s(uj);

    return 0;
}
