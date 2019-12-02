#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cassert>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
bool used[10000000];
int numToArr(int num,int arr[]){
    int pos=0;
    while(num){
        arr[pos++]=num%10;
        num/=10;
    }
    return pos;
}

int arrToNum(int arr[],int l){
    int num=0;
    if(arr[l-1]==0) return -1;
    for(int i=l-1;i>=0;i--){
        num=num*10+arr[i];
    }
    return num;
}

void shift(int arr[],int l){
    int last=arr[0];
    for(int i=0;i<l-1;i++){
        arr[i]=arr[i+1];
    }
    arr[l-1]=last;
}

int cnt(int num,int A,int B){
    int arr[10];
    int l=numToArr(num,arr),N,counter=0;
    for(int i=0;i<l-1;i++){
        shift(arr,l);
        N=arrToNum(arr,l);
        if(N>=A && N<=B && !used[N]){
            counter++;
            used[N]=true;
        }
    }
    return counter;
}

int main(){
    int T,A,B;
   // freopen("C-small-attempt0.IN","r",stdin);
    //freopen("C-small-attempt0.OUT","w",stdout);
    scanf("%d",&T);
    for(int I=1;I<=T;I++){
        scanf("%d%d",&A,&B);
        long long ans=0;
        for(int i=A;i<=B;i++) used[i]=false;
        
        for(int i=A;i<=B;i++){
            if(!used[i]){
                used[i]=true;
                long long p=cnt(i,A,B);
               // cout<<i<<" "<<p<<endl;
                if(p>0) ans+=p*(p+1)/2;
            }
        }
        printf("Case #%d: %lld\n",I,ans);
    }
    return 0;
}
