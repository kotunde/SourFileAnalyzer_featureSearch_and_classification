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
#define PI acos(-1.0)

using namespace std ;

int a[1001][1001] ;
int n , m , k , T , x , y ;

int main()
{
	freopen("B-small.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	
	scanf("%d", &T);
	for (int cases = 1 ; cases <= T ; cases++){
        scanf("%d %d %d" , &n , &m , &k) ;
        memset(a , -1 , sizeof(a)) ;
        a[0][0] = 0 ;
        for (int i = 1 ; i <= n ; i++){
            scanf("%d" , &x);
            for (int j = 0 ; j <= m ; j++){
                if (a[i-1][j] != -1){
                        if (x > 1)
                           if (j != m){
                                     int tmp = x % 3 ;
                                     if (tmp == 0){ y = (x - 3) / 3 + 2 ; }
                                     else if (tmp == 1){ y = (x - 4) / 3 + 2 ;}
                                     else { y = (x - 2) / 3 + 2 ;}
                              int cnt = 0;
                              if (y >= k) cnt++ ;
                              a[i][j+1] = max(a[i][j+1] , a[i-1][j] + cnt) ;
                           }
                           
                           y = x / 3 ;
                           if (x % 3 != 0) y++ ;
                              int cnt = 0;
                              if (y >= k) cnt++ ;
                           a[i][j] = max(a[i][j] , a[i-1][j] + cnt) ;
                        }
                }
            }
                printf("Case #%d: %d\n" , cases , a[n][m]) ;
        }
}
