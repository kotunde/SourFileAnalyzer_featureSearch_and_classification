#include <iostream>
#include <fstream>
#include <set>
#include "StrangeCompare.h"

using namespace std;

int main(){
    ifstream ifs("bemenete.txt");

    string line;
    getline(ifs, line);

    set<string, StrangeCompare> nevek(line);
    while(getline(ifs, line)){
        nevek.insert(line);
        //cout<<line<<endl;
    }
    ifs.close();

    for(auto& n: nevek){
        cout<<n<<endl;
    }
    return 0;
}
