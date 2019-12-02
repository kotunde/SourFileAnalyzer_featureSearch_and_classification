#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("regiszter0.txt");
    map<string, pair<int,int>> registry;

    string line;
    bool flag = false;
    while (getline(f, line)) {
        istringstream iss(line);
        if(line.size() == 0) {
            flag = true;
        }
        if(!flag) {
            string name;
            int byear, dyear=0;
            iss>>name>>byear;
            if(iss) {
                iss>>dyear;
            }
            registry.insert({name, {byear, dyear}});
        }
        else {
            string name;
            int byear, dyear=0;
            iss>>name>>dyear;

            auto it = registry.find(name);
            if (it != registry.end())
                it->second.second= dyear;
        }




    }

    // OR
    // registry.insert(make_pair(name, make_pair(byear, dyear)));

    for (x : registry)
        cout<<x.first<<" "<<"\n";
}
