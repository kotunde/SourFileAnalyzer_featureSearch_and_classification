#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int a,b,c,d,e,f;
//t组数据，n个人，s个surprising，最高分要大于等于p，然后有N个分数。 
int n,t,s,p;
int sup[31]; //表示如果是i的话，如果它是suprising的，可以最大到多少 
int put[31]; //表示如果是i的话，如果它不是suprising的，可以最大到多少 
int main()
{
    for (a=0;a<=30;a++)
    {
        put[a]=a/3;
        if (a%3!=0) put[a]++;
        //cout<<a<<' '<<put[a]<<endl;
    }
    sup[0]=0;
    for (a=1;a<=30;a++)
    {
        sup[a]=a/3;
        if (a%3==0) sup[a]++;
        if (a%3==1) sup[a]++;
        if (a%3==2) sup[a]+=2;
        //cout<<a<<' '<<sup[a]<<endl;
    }
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    cin>>t;
    for (c=1;c<=t;c++)
    {
          cin>>n>>s>>p;
          int sum=0,x;
          for (a=1;a<=n;a++)
          {
              cin>>x;
              //cout<<x<<' '<<put[x]<<' '<<sup[x]<<' '<<s<<endl;
              if (put[x]>=p) sum++;
              else if (sup[x]>=p && s>0) {sum++; s--;}
          }
          printf("Case #%d: %d\n",c,sum);
    }
    //while (1);
}
