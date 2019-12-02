#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 105;
int f[N][2],tp,ans[N],n,s,p;

int main()
{
    freopen("B-small-attempt4.in","r",stdin);
    freopen("t.txt","w",stdout);
   int t;
   scanf("%d",&t);
   for(int k = 1 ;k <= t; k++)
    {
        scanf("%d%d%d",&n,&s,&p);
        memset(f,0,sizeof(f));
        for(int i = 1; i <= n; i++ )
         {
             scanf("%d",&tp);
             if(tp%3 == 0)
              {
                  f[i][0] = tp/3;
                  if(tp >= 3)
                  f[i][1] = tp/3+1;
              }
             if(tp%3 == 1)
              {
                  f[i][0] = tp/3+1;
                  if(tp >= 4)
                  f[i][1] = tp/3+1;
              }
              if(tp%3 == 2)
              {
                  f[i][0] = tp/3 + 1;
                  f[i][1] = tp/3 + 2;
              }
         }
         int ans1 = 0,ans2 = 0;
         for(int i =1;i <= n;i++)
          {
              //cout<<f[i][0]<<"  "<<f[i][1]<<endl;
              if(f[i][0] >= p) ans1++;
              else if(f[i][1] >= p) ans2++;
          }
         printf("Case #%d: %d\n",k,ans1+min(s,ans2));
    }
    return 0;
}
