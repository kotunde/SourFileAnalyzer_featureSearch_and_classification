#include<cstdio>
using namespace std;
int tmp[10];
int main ()
{
    freopen("C-small-attempt0.in","r",stdin);
	freopen("out.out","w",stdout);
    int nn,a,b,c,num,ans;
    bool flag;
    scanf("%d",&nn);
    for(int i=1; i<=nn; ++i)
    {
        scanf("%d%d",&a,&b);
        printf("Case #%d: ",i);
        num=0;
        c=a;
        while(c)
        {
            c=c/10;
            ++num;
        }
        if(num==1)
        {
            printf("0\n");
            continue;
        }
        ans=0;
        for(int j=a; j<=b; ++j)
        {
            tmp[0]=j;
            for(int k=1; k<num; ++k)
            {
                tmp[k]=tmp[k-1]%10;
                if(tmp[k]==0)
                {
                    tmp[k]=tmp[k-1]/10;
                    continue;
                }
                else
                {
                    for(int t=1; t<num; ++t)
                        tmp[k]*=10;
                    tmp[k]+=tmp[k-1]/10;
                    if(tmp[k]>j && tmp[k]<=b)
                    {
                        flag=1;
                        for(int t=1; t<k; ++t)
                            if(tmp[k]==tmp[t])
                            {
                                flag=0;
                                break;
                            }
                        if(flag)
                            ++ans;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
