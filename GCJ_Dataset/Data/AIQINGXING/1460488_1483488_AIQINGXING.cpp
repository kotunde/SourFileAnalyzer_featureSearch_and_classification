#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int a,b,c,d,e,f;
int t;
int sum;
string l,r;
int pan(string i,string j)
{
    int a,b;
    if (i.size()>j.size()) return 1; //1代表第一个大
    if (j.size()>i.size()) return 0; //0代表第二个大
    for (a=0;a<i.size();a++)
    {
        if (i[a]>j[a]) return 1;
        if (i[a]<j[a]) return 0;
    }
    return 0;
}

void dfs(string s)
{
     int a,b;
     if (pan(s,r)==1) return; //如果比r都大了就return吧。
     //cout<<s<<' '<<u<<endl;
     if (pan(l,s)==0) //大于等于l就可以 
     {
        int fuck=1;
        string cao=s;
        for (a=1;a<s.size();a++)
        {
            s=s+s[0];
            s.erase(0,1);
            //cout<<s<<endl;
            if (pan(s,r)==0 && s>cao)
            {
               sum++;
            } 
        }
        //sum=sum+fuck*(fuck-1)/2;
     }
     for (char ch='0';ch<='9';ch++)
     {
         dfs(s+ch);
     }
} 


int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    cin>>t;
    for (f=1;f<=t;f++)
    {
        sum=0;
        cin>>l>>r;
        string s;
        for (a=1;a<=9;a++)
        {
            s="";
            char ch='0'+a;
            s=s+ch;         //   dfs("",1); //1代表还没有前缀。
            dfs(s);
        }
        printf("Case #%d: %d\n",f,sum);
    }
}
        
        
        
