#include <iostream>
#include <map>
#include <utility>
#include <sstream>
#include <fstream>


using namespace std;

int main()
{
    map<string, pair<int,int>> regiszter;
    string name;
    int by, dy=0;
    ifstream f("regiszter0.txt");
    if(!f){
        cout<<"file error";
        return 0;
    }
    string line;
    while(! f.eof()){
        getline(f,line);
        if(line.size()==0){
            break;
        }
        istringstream iss(line);
        iss>>name;
        iss>>by;
        iss>>dy;
        regiszter.insert(make_pair(name, make_pair(by,dy)));
    }
    while(! f.eof()){
        getline(f,line);
        istringstream iss(line);
        iss>>name;
        iss>>dy;
        regiszter.insert(make_pair(name, make_pair(by,dy)));
    }
    f.close();
    return 0;
}
