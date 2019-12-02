// Author: Adam Krasuski

#include <cstdio>
#include <vector>

int min(int a,int b){
    if (a<b){
        return a;
    }
    return b;
}

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        vector<int>numbers;
        for(int j=0;j<n;j++){
            int a;
            scanf("%d",&a);
            numbers.push_back(a);
        }
        int moves=0;
        while(!numbers.empty()){
            int minim=2e9;
            int ind=0;
            for(int k=0;k<numbers.size();k++){
                if(numbers[k]<minim){
                    minim=numbers[k];
                    ind=k;
                }
            }
            //now, number at index ind is the smallest
            moves+=min(ind,numbers.size()-ind-1);
            numbers.erase(numbers.begin()+ind);


        }
        printf("Case #%d: %d\n",i+1,moves);

    }
}
