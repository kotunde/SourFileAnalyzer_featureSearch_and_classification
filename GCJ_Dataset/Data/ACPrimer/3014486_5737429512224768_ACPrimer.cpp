#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <stdlib.h>
using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 10005;
int a[maxn];
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int T,n,x,ncase=0;
    cin>>T;
    while(T--){
        cin>>n>>x;
        int mid = (x+1)/2,ans=0;
        for(int i=0;i<n;i++) cin>>a[i];
        qsort(a,n,sizeof(a[0]),cmp);
        int p=0,q;
        for(int i=0;i<n;i++)
        {
            if(a[i]<mid) p++;
        }
        q=p; p--;
        int left = 0;
        while(q+1<n&&a[q]+a[q+1]<=x){
            q+=2;
            ans++;
        }
        while(p>=0&&q<n){
            if(a[p]+a[q]<=x)
            {
                ans++;
                p--;
                q++;
            }
            else
            {
                left++;
                p--;
            }
        }
        ans=ans+(n-q)+(p+left+2)/2;
        printf("Case #%d: %d\n",++ncase,ans);
    }
    return 0;
}
/*
100
3 100
10 20 70
4 100
30 40 60 70
5 100
10 20 30 40 60
3 10
1 1 1
4 10
2 2 2 2
4 10
5 5 5 5
10 10
1 2 3 4 5 6 7 8 9 10
10 10
1 3 8 8 2 3 5 9 1 10
12 10
1 1 1 3 8 8 2 3 5 9 1 10
*/
