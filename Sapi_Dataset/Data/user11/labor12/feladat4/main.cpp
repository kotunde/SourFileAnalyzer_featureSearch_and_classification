#include <set>
#include <iostream>
#include <iterator>
#include <string>
#include <functional>
#include <fstream>
#include <map>
#include <utility>
#include <sstream>
using namespace std;

int main()
{
    string line;
    ifstream file("register1.txt");
    if(!file)
    {
        cerr<<"file megnyitasi hiba"<<endl;
        return 0;
    }

    string name;
    map<string,pair<int,int>>registry;
    while(getline(file,line))
    {
        if(line.empty()){
            break;
        }
        int by,dy=0;


        stringstream iss(line);
        iss>>name>>by;
        if(iss)
        {
            iss>>dy;

        }
        registry.insert(make_pair(name,make_pair(by,dy)));

    }


    cout<<registry.size()<<endl;

    while(getline(file,line))
    {
        stringstream iss(line);
        int dy;
        iss>>name>>dy;
        auto pos =registry.find(name);
        if(pos!=registry.end())
        {
            pos->second.second=dy;
        }
    }

    int num=0;

    for(auto & a:registry)
    {
        if(a.second.second!=0)
        {
            cout<<a.first<<" "<<a.second.first<<" "<<a.second.second<<endl;
            ++num;
        }
    }
    cout<<num<<endl;
    return 0;
}
