#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int n, k;
const int N = 1000+5;
string s[ N ];
int a[ N ];
int mask[ N ];
int last[ N ];
int d[ N ][ N ];
int main()
{
   freopen("D-small-attempt0.in", "r", stdin);
   freopen("D-small-attempt0.out", "w", stdout);
   //freopen("input.txt", "r", stdin);
   int T = 0;
   cin>>T;
   for(int te = 1; te <= T; ++ te)
   {
      cin>>n>>k;
      int S = 0;
      for(int i = 0; i < n; ++ i)
      {
         cin>>s[i];
         S+=s[i].size();
      }
      S+=k;

      sort(s, s+n);
      for(int i = 0; i+1 < n; ++ i)
      {
         a[i] = 0;
         for(int j = 0; j < (int)s[i].size() && j < (int)s[i+1].size(); ++ j)
         {
            if(s[i][j]!=s[i+1][j])break;
            a[i] = j+1;
         }
      }
      for(int i = 0; i < n; ++ i)mask[i] = 1;
      int ans = 0, val = 0;
      for(int i = 0; i+1 < n; ++ i)
      {
         for(int j = i+1;j < n; ++ j)
         {
            d[i][j] = a[j-1];
            if(j-1 > i)d[i][j] = min(d[i][j], d[i][j-1]);
         }
      }
      while(1)
      {
         int res = S;
         for(int i = 1; i <= k; ++ i)last[i] = -1;
         for(int i = 0; i < n; ++ i)
         last[ mask[i] ] = i;
         for(int i = 1; i <= k; ++ i)
         {
            if(last[i]==-1)goto x;
            last[i] = -1;
         }
         for(int i = 0; i < n; ++ i)
         {
            if(last[ mask[i] ]!=-1)
            {
               res-=d[ last[ mask[i]] ][ i ];
            }
            last[ mask[i] ] = i;
         }
         if(ans < res)
         {
            ans = res;
            val = 0;
         }
         if(ans==res)
            ++ val;
x:
         int j = 0;
         while(mask[j]==k)
         {
            mask[j] = 1;
            ++ j;
         }
         if(j < n)
         ++mask[j];
         else
            break;
      }
      cout<<"Case #"<<te<<": "<<ans<<" "<<val<<endl;
   }
   return 0;
}
