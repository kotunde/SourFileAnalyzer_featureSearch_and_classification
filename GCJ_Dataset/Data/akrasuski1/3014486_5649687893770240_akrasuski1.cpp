// Author: Adam Krasuski

#include <cstdio>
#include <vector>
#include <string>
#include <set>

using namespace std;

vector<string>strings;
vector<set<string> >prefixes;
int number_of_servers;

int biggest;
int number_of_ways;

int factorial(int n){
    if(n==0||n==1){
        return 1;
    }
    return n*factorial(n-1);
}

void subsets(int subset_indices[],int done,int used_servers){
    if(done==strings.size()){
        if(used_servers==number_of_servers){
            set<string>server_prefixes[number_of_servers];


            for(int i=0;i<strings.size();i++){
                int ind=subset_indices[i];
                server_prefixes[ ind ].insert(prefixes[i].begin(),prefixes[i].end());
            }

            int sum=0;
            for(int i=0;i<used_servers;i++){
                sum+=server_prefixes[i].size();
            }
            if(sum>biggest){
                biggest=sum;
                number_of_ways=1;
            }
            else if(sum==biggest){
                number_of_ways++;
            }

        }
    }
    else{
        for(int i=0;i<used_servers;i++){
            subset_indices[done]=i;
            subsets(subset_indices,done+1,used_servers);
        }
        if(used_servers<number_of_servers){
            subset_indices[done]=used_servers;
            subsets(subset_indices,done+1,used_servers+1);
        }
    }
}

int sub_ind[20];

char buff[109];

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int m,n;
        scanf("%d %d",&m,&n);
        strings.clear();
        prefixes.clear();
        set<string>emp;
        for(int j=0;j<m;j++){
            scanf("%s",buff);
            string s(buff);
            strings.push_back(s);
            prefixes.push_back(emp);
        }
        for(int j=0;j<m;j++){
            for(int k=0;k<=strings[j].length();k++){
                string pref=strings[j].substr(0,k);
                prefixes[j].insert(pref);
            }
        }
        number_of_servers=n;
        biggest=0;
        number_of_ways=0;
        subsets(sub_ind,0,0);

        printf("Case #%d: %d %d\n",i+1,biggest,number_of_ways*factorial(n));


    }


}
