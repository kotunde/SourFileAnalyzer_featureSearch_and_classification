#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#define N 2000020
using namespace std;
int T,t,n,a,b,i,j,k,ans,f[N];

double lnC(int n, int m){
  if (m>n) return 0;
  if (m<n/2.0) m=n-m;
  int i,j; double s1=0;
  for (int i=m+1;i<=n;i++)
    s1+=log((double)i);
    double s2=0;
    int ub=n-m;
    for (j=2;j<=ub;j++)
      s2+=log((double)j);
    return s1-s2;
}
int C(int n, int m) {
  if (m>n) return 0;
  return floor(exp(lnC(n, m))+0.5);
}

int calc(int x) {
  if (f[x]!=t) f[x]=t; else return 0;
  if (x<10) return 0;
  static char st[1024];
  sprintf(st,"%d",x);
  int i,j,res=1,l=strlen(st);
  string s=st,s2;
  s2=s.substr(1)+s[0];
  for (i=1;i<l;i++) {
    j=atoi(s2.c_str());
    if (a<=j&&j<=b&&f[j]!=t)
      f[j]=t,res++;
    s2=s2.substr(1)+s2[0];
  }
  return C(res,2);
}

int main() {
  freopen("C-small-attempt0.in","r",stdin);
  freopen("out1.txt","w",stdout);
  scanf("%d",&T);
  for (t=1;t<=T;t++) {
    scanf("%d%d",&a,&b);
    for (ans=0,i=a;i<=b;i++)
      ans+=(k=calc(i));
    printf("Case #%d: %d\n",t,ans);
  }
  return 0;
}
