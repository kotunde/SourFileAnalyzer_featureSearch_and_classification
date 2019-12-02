#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

const int N = 10000+4;
int n;
int a[ N ], b[ N ], p[ N ];
map< int, int > mp;
int dp[ N ], pos[ N ];
int main()
{
   freopen("B-small-attempt1.in", "r", stdin);freopen("B-small-attempt1.out", "w", stdout);
   //freopen("input.txt", "r", stdin);//freopen("ouput.txt", "w", stdout);
   int T;
   cin>>T;
   for(int te = 1; te <= T; ++ te)
   {
      cin>>n;
      for(int i = 1; i <= n; ++ i)
      {
         cin>>a[i];
         b[i] = a[i];
      }
      sort(b+1, b+n+1);
      mp.clear();
      for(int i = 1; i <= n; ++ i)mp[ b[i] ] = i;
      for(int i = 1; i <= n; ++ i)
      {
         p[i] = mp[ a[i] ];
         pos[ p[i] ] = i;
      }
      //for(int i = 1; i <= n; ++ i)cout<<p[i]<<" "<<pos[i]<<",";
      dp[n+1] = 0;
      for(int i = n; i >= 1; -- i)
      {
         int l = 0, r = 0;
         for(int j = 1; j < pos[ i ]; ++ j)
            if(p[j] > i)++l;
         for(int j = pos[i]+1; j <= n; ++ j)
            if(p[j] > i)++r;
         dp[i] = dp[i+1]+min(l, r);
      }
      printf("Case #%d: %d\n", te, dp[1]);
   }
   return 0;
}
