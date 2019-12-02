#include<stdio.h>
#include<string.h>
int main()
{
    char S1[101],S2[101];
    int T,z,cnt1,cnt2,count,d,N;
    scanf("%d",&T);
    for(z=1;z<=T;z++)
    {
    	scanf("%d",&N);
    	d=0;
        scanf("%s",&S1);
        scanf("%s",&S2);
        int i=0,j=0;
        if(S1[0]==S2[0])
        {
            count=0;
            while(i<strlen(S1)&&j<strlen(S2))
            {
                cnt1=1;cnt2=1;
                while(S1[i]==S1[i+1])
                {
                    cnt1++;
                    i++;
                }
                while(S2[j]==S2[j+1])
                {
                    cnt2++;
                    j++;
                }
                if(cnt1>cnt2)
                    count+=cnt1-cnt2;
                else
                    count+=cnt2-cnt1;
                i++;j++;
 
                if(S1[i]!=S2[j])
                {
                     d=1;
                    break;
                }
            }  
                if(d==1)
                    printf("Case #%d: Fegla Won\n",z);
                else
                    printf("Case #%d: %d\n",z,count);
 
        }
        else
           printf("Case #%d: Fegla Won\n",z);
    }
    return 0;
}