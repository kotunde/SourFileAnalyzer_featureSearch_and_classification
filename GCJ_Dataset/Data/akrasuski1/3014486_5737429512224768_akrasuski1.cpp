// Author: Adam Krasuski

#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;

int cmp(int a,int b){
    return a>b;
}

int sizes[10009];

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n,capacity;
        scanf("%d %d",&n,&capacity);
        for(int j=0;j<n;j++){
            scanf("%d",&sizes[j]);
        }
        sort(sizes,sizes+n,cmp);
        int left=0;
        int right=n-1;
        int cnt=0;//number of doubles
        while(left<right){
            //try to put right into left
            if(sizes[right]+sizes[left]<=capacity){
                //yay, it is okay
                cnt++;
                right--;
                left++;
            }
            else{
                //can't be done - move to next biggest
                left++;
            }
        }
        printf("Case #%d: %d\n",i+1,n-cnt);
    }
}
