#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <sstream>
#include <map>

using namespace std;

int main()
{
    map<string,pair<int,int>> registry;

    string line;
    ifstream file( "regiszter2.txt" );

    //beolvasas
    if (!file)
    {
        cerr << "Fajl megnyitasi hiba" << endl;
        return 1;
    }
    while (getline(file,line))
    {
        string name; int birthy, deathy = 0;
        if(line.empty()){
            break;
        }
        istringstream iss(line);
        iss >> name >> birthy;
        if  (iss)
        {
            iss >> deathy;
        }
        registry.insert(make_pair(name,(make_pair(birthy,deathy))));
    }
    //cout << registry.size() << endl;


    while (getline(file,line))
    {
        string name; int deathy = 0;
        istringstream iss(line);
        iss >> name >> deathy;
        auto pos = registry.find(name);
        if (pos != registry.end()){
            pos->second.second = deathy;
        }
    }

    /*for (auto& x : registry){
        cout << x.first << " " << x.second.first << " " << x.second.second << endl;
    }*/

    int counter = 0;
    for (auto& x : registry){
        if (x.second.second != 0){
            //cout << x.first << " " << x.second.first << " " << x.second.second << endl;
            ++counter;
        }
    }

    cout << counter << endl;

    return 0;
}
