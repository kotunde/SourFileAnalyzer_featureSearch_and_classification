#include <iostream>
#include <map>
#include <utility>
#include<fstream>
#include<string.h>
#include<sstream>
using namespace std;

int main()
{
    map<string,pair<int,int>>registry;
    ifstream ifs("be.txt");
    string line;
    getline(ifs,line);
    while(line.size()!=0)
    {
        //cout<<line<<endl;
        istringstream iss(line);
        string name;
        int byear,dyear=0;
        iss >> name >>byear;
        if(iss)
        {
            iss>>dyear;
        }
        registry.insert({name,{byear,dyear}});
        getline(ifs,line);
    }

    getline(ifs,line);
    while(line.size()!=0){
        //cout<<line<<endl;
        istringstream iss(line);
        string name;
        int dyear;
        iss >> name >>dyear;
        auto poz = registry.find(name);
        if( poz != registry.end()){
            (poz->second).second = dyear;
        }
        getline(ifs,line);
    }
    int aux=0;
    for( auto& x: registry )
    {
        if(x.second.second!=0)
            //cout<< x.first <<" "<<x.second.first<<" "<<x.second.second<<" \n";
            aux++;
    }
    cout<<aux<<endl;







    return 0;
}
