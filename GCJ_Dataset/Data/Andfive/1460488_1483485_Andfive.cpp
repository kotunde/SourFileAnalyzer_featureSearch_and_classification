#include<cstdio>
#include<cstring>
using namespace std;
char m[105];
char key[27]="yhesocvxduiglbkrztnwjpfmaq";
int main ()
{
    int n,l;
    char c;
    scanf("%d",&n);
    scanf("%c",&c);
    for(int i=1;i<=n;++i)
    {
        gets(m);
        l=strlen(m);
        for(int j=0;j<l;++j)
            if(m[j]!=' ')
                m[j]=key[m[j]-'a'];
        printf("Case #%d: %s\n",i,m);
    }
    return 0;
}
