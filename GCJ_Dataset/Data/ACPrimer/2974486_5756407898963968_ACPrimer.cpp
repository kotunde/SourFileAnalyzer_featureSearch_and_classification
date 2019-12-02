#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <ctype.h>
using namespace std;
int a[4][4],b[4][4];
int main()
{
    int T,n,m,ncase=0,i,j;
    FILE* fp = fopen("a.in","r");
    FILE* fp2 = fopen("a.out.txt","w");
    fscanf(fp,"%d",&T);
    while(T--){
        fscanf(fp,"%d",&n); n--;
        for(i=0;i<4;i++) for(j=0;j<4;j++) fscanf(fp,"%d",&a[i][j]);
        fscanf(fp,"%d",&m); m--;
        for(i=0;i<4;i++) for(j=0;j<4;j++) fscanf(fp,"%d",&b[i][j]);
        int cnt=0,ans;
        for(i=0;i<4;i++) for(j=0;j<4;j++) if(a[n][i] == b[m][j]) { cnt++; ans=a[n][i]; }
        if(cnt==0){
            fprintf(fp2,"Case #%d: Volunteer cheated!\n", ++ncase);
        }else if(cnt>1){
            fprintf(fp2,"Case #%d: Bad magician!\n", ++ncase);
        }else fprintf(fp2,"Case #%d: %d\n", ++ncase, ans);
    }
    return 0;
}
/*
3,1,2
1,2,3,4,5
5,4,3,2,1
*/
