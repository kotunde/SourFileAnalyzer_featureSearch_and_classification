#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int a,b,c,d,e,f;
char ch[27];
int vis[27];
int n,t;
int main()
{
    freopen("A-small-attempt1(1).in","r",stdin);
    freopen("A-small-attempt1(1).out","w",stdout);
    string s1="ejp mysljylc kd kxveddknmc re jsicpdrysi";
    string s2="our language is impossible to understand";
    string s3="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    string s4="there are twenty six factorial possibilities";
    string s5="de kr kd eoya kw aej tysr re ujdr lkgc jv";
    string s6="so it is okay if you want to just give up";
    for (a=0;a<s1.size();a++)
    if (s1[a]!=' ')
        ch[s1[a]-'a']=s2[a];
    for (a=0;a<s3.size();a++)
    if (s3[a]!=' ')    
        ch[s3[a]-'a']=s4[a];
    for (a=0;a<s5.size();a++)
    if (s5[a]!=' ')    
        ch[s5[a]-'a']=s6[a];
    char fuck[1000];
    ch['q'-'a']='z';
    ch['z'-'a']='q';
    //for (a=0;a<26;a++) cout<<char(a+'a')<<' '<<ch[a]<<endl;
    //for (a=0;a<26;a++) if (ch[a]) vis[a]=1;
    //for (a=0;a<26;a++) if (vis[a]==0) cout<<char('a'+a)<<endl;
    cin>>t;
    gets(fuck);
    for (b=1;b<=t;b++)
    {
        gets(fuck);
        printf("Case #%d: ",b);
        c=strlen(fuck);
        for (a=0;a<c;a++) if (fuck[a]==' ') cout<<' '; else cout<<ch[fuck[a]-'a'];
        cout<<endl;
    }
    //system("pause");
}
