/*
     Author : Akai
     Problem : A
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

const char a[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'} ;

char s1[1005] ;
int n ; 

int main(){
    freopen("A-small.in" , "r" ,  stdin);
    freopen("A-small.out" , "w" , stdout);
    scanf("%d" , &n);
    gets(s1);
    for (int i = 1 ; i <= n ; i++){
        gets(s1);
        int L = strlen(s1) ;
        printf("Case #%d: ", i);
        for (int i = 0 ; i < L ; i++) if (s1[i] == ' ') printf(" ");else printf("%c" , a[s1[i] - 'a']) ;
        printf("\n");
    }
}
    
