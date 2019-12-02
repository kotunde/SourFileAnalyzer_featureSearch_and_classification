#include<bits/stdc++.h>
using namespace std;
int a,b,arr1[4][4],arr2[4][4];
#define s(x) scanf("%d",&x)
#define READ(f) freopen(f,"r",stdin);
#define WRITE(f) freopen(f,"w",stdout);
int main(){
    READ("1.in");
    WRITE("1.out");
    int t;cin>>t;
    for(int caseid=1;caseid<=t;++caseid){
        s(a);a--;
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
                s(arr1[i][j]);
        vector<bool> v(17,false);
        for(int j=0;j<4;++j)v[arr1[a][j]]=1;
        s(b);b--;
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
                s(arr2[i][j]);
        int cnt=0,ans;
        for(int j=0;j<4;++j)
        if(v[arr2[b][j]]==1){ans=arr2[b][j];cnt++;}
        printf("Case #%d: ",caseid);
        if(cnt==1)printf("%d",ans);
        else if(cnt==0)printf("Volunteer cheated!");
        else printf("Bad magician!");
        printf("\n");
    }
}
