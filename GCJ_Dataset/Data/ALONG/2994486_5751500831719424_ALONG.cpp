#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int n,t;
    int i,j,k;
    char str[200][200];
    int c=1;
    int len=0;
    scanf("%d",&t);
    char short_str[200][200];
    int cnt_str[200][200]; 
    while(c<=t)
    {
        scanf("%d",&n);
        for( i=0; i<n; i++)
        {
            scanf("%s", str[i]);
        }
        for(i=0; i<200; i++)
            for(j=0; j<200; j++)
            {
                short_str[i][j]=0;
                cnt_str[i][j]=0;
            }

        for(i=0; i<n; i++)
        {
            short_str[i][0]=str[i][0];
            cnt_str[i][0]=1;
            for(j=1, k=0; str[i][j]!=0; j++)
            {
                if( str[i][j] == short_str[i][k])
                    cnt_str[i][k]++;
                else 
                {
                    k++;
                    short_str[i][k]=str[i][j];
                    cnt_str[i][k]=1;
                }
            }
        }
        int isSame=1;
        for( j=0; j<100; j++)
        {
            char ch=short_str[0][j];
            for(i=1; i<n; i++)
                if( ch != short_str[i][j])
                {
                    isSame=0;
                    break;
                }
            if( isSame == 0)
                break;
        }
        if( isSame == 0)
        {
            cout<<"Case #"<<c<<": Fegla Won"<<endl;
        } else {
            int cnt=0;
            for( j=0; j<100; j++)
            {
                char ch=short_str[0][j];
                if( ch == 0)
                    break;
                double avg=0;
                for(i=0; i<n; i++)
                    avg+=cnt_str[i][j];
                avg/=n;
                int int_avg = (int)avg;
                if( avg > int_avg+0.5000)
                    int_avg+=1;
                for(i=0; i<n; i++)
                    cnt+= abs(cnt_str[i][j]-int_avg);
            }
            cout<<"Case #"<<c<<": "<<cnt<<endl;
        }
        c++;
    }
    return 0;
}
