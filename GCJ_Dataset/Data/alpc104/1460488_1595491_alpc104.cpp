#include <cstdio>
#define N 128
int main() {
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int T,t,n,s,p,a[N];
  scanf("%d",&T);
  for (t=1;t<=T;t++) {
    scanf("%d%d%d",&n,&s,&p);
    int i,j,k,ans=0;
    for (i=1;i<=n;i++) {
      scanf("%d",a+i),j=a[i]/3;
      //printf("t=%d ans=%d -> ",a[i],ans);
      switch (a[i]%3) {
        case 0:
          if (a[i]==0) {
            if (!p) ans++;
            break;
          }
          if (j>=p) ans++; else
          if (s&&j+1>=p) ans++,s--;
          break;
        case 1:
          if (a[i]==1) {
            if (p==1) ans++;
            break;
          }
          if (j+1>=p) ans++;
          break;
        case 2:
          if (a[i]==2) {
            if (1>=p) ans++; else
            if (s&&2>=p) ans++,s--;
          }
          if (j+1>=p) ans++; else
          if (s&&j+2>=p) ans++,s--;
      }
      //printf("%d\n",ans);
    }
    printf("Case #%d: %d\n",t,ans);
  }
  return 0;
}
