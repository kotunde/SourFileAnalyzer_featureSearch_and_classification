#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
using namespace std;
const int maxn=1005;
double a[maxn],b[maxn],c[maxn];
int vis[maxn];
int cmp(const void *a,const void *b)
{
    return *(double *)a > *(double *)b ? 1 : -1;
}
int main()
{
    int T,ncase=0,n,i,j;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int ans1=0,ans2=0;
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++) scanf("%lf",&a[i]);
        for(i=0;i<n;i++) scanf("%lf",&b[i]);
        qsort(a,n,sizeof(a[0]),cmp);
        qsort(b,n,sizeof(b[0]),cmp);
        for(i=0;i<n;i++)
        {
            int idx=-1;
            for(j=0;j<n;j++)
            {
                if(!vis[j] && b[j]>a[i]) { idx=j; break; }
            }
            if(idx==-1)
            {
                ans2++;
                for(j=0;j<n&&!vis[j];j++);
                vis[j]=1;
            }
            else vis[idx]=1;
        }
        /*int c1=0,c2=0;
        for(i=0;i<n;i++) if(a[i]<b[0]) c1++;
        for(i=0;i<n;i++) if(b[i]>a[n-1]) c2++;
        ans1=c1>c2?c1:c2;*/
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
        {
            int idx=-1;
            for(j=0;j<n;j++)
            {
                if(!vis[j] && a[j]>b[i]) { idx=j; break; }
            }
            if(idx==-1)
            {
                ans1++;
                for(j=0;j<n&&!vis[j];j++);
                vis[j]=1;
            }
            else vis[idx]=1;
        }
        printf("Case #%d: %d %d\n", ++ncase, n-ans1, ans2);
    }
    return 0;
}
/*
3,1,2
1,2,3,4,5
5,4,3,2,1
*/
