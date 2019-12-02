#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1010;
char map[27]={'y','h','e','s','o','c','v','x','d','u',
                            'i','g','l','b','k','r','z','t','n','w',
                                'j','p','f','m','a','q'};
char str[N];
int main()
 {
     freopen("A-small-attempt5.in","r",stdin);
     freopen("t.txt","w",stdout);
     int t;
     scanf("%d\n",&t);
     for(int i = 1 ;i <= t ;i++)
      {
          printf("Case #%d: ",i);
          gets(str);
          int len = strlen(str);
          for(int j = 0 ;j < len ;j++)
           {
               if(str[j] == ' ') printf(" ");
               else printf("%c",map[str[j]-'a']);
           }
           printf("\n");
      }
    return 0;
 }
