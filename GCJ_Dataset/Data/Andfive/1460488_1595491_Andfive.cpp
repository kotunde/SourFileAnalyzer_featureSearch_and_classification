#include<cstdio>
using namespace std;
int m[105];
int main ()
{
    freopen("B-small-attempt0.in","r",stdin);
	freopen("out.out","w",stdout);
    int nn,n,s,p,num1,num2;
    scanf("%d",&nn);
    for(int i=1; i<=nn; ++i)
    {
        scanf("%d%d%d",&n,&s,&p);
        for(int j=1; j<=n; ++j)
            scanf("%d",&m[j]);
        printf("Case #%d: ",i);
        num1=num2=0;
        for(int j=1;j<=n;++j)
            if(m[j]>=3*p-2)
                ++num1;
            else if(p!=0 && p!=1 && m[j]>=3*p-4)
                ++num2;
        printf("%d\n",num1+((num2>=s)?s:num2));
    }
    return 0;
}
