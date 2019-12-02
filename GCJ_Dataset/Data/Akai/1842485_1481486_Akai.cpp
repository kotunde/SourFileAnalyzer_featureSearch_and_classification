/*
     Author : Akai
     Problem :
     Time :
*/
#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define PI acos(-1.0)

using namespace std ;

int f[300000] , d[300000] , l[300000] ; 

int T , r ,cases , n ;

void change(int i , int j){
     f[j] = max(f[j] , d[j] - d[i]);
}

int main(){
    freopen("A-small.in" , "r" , stdin);
    freopen("A-small.out" , "w" , stdout);
    scanf("%d" , &T);
    while (T--){
          printf("Case #%d: " , ++cases);
          scanf("%d" , &n);
          for (int i = 1 ; i <= n ; i++) scanf("%d%d" , &d[i] , &l[i]);
          scanf("%d" , &r);
          memset(f , 255 , sizeof(f)) ;
          f[1] = d[1] ;
          for (int i = 1 ; i <= n ; i++) if (f[i] > 0){
              f[i] = min(f[i] , l[i]);
              for (int j = i + 1 ; j <= n ; j++)
                  if (d[j] - d[i] > f[i]) break ; else change(i , j) ;
          
          }
          bool f1 = 0 ;
          for (int i = 1 ; i<= n ; i++) if (d[i] + f[i] >= r){
              puts("YES");
              f1 = 1 ;
              break ;
          } 
          if (!f1) puts("NO");     
    }
}
