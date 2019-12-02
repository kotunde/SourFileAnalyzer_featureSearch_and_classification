#include <iostream>
#include <cstdio>
using namespace std;
const int N = 100000+5;
int n, X, T, a[ N ], q[ N ];
int main()
{
   freopen("A-small-attempt2.in", "r", stdin);freopen("A-small-attempt2.out", "w", stdout);
   //freopen("input.txt", "r", stdin);freopen("ouput.txt", "w", stdout);
   cin>>T;
   for(int te = 1; te <= T; ++ te)
   {
      cin>>n>>X;
      for(int i = X; i >= 0; -- i)q[i] = 0;

      for(int i = 1; i <= n; ++ i)
      {
         cin>>a[i];
         ++ q[ a[i] ];
      }
      int res = 0;
      for(int i = X; i >= 0; -- i)
      {
         while(q[i])
         {
            ++ res;
            -- q[i];
            for(int j = X-i; j >= 1; -- j)
            {
               if(q[j])
               {
                  -- q[j];
                  break;
               }
            }
         }
      }
      cout<<"Case #"<<te<<": ";
      cout<<res<<endl;
   }
   return 0;
}
