#include <cstdio>
#include <algorithm>
struct dat{
  int val,ord;
} a[1024];

int cmp(dat a,dat b) {
  return a.val!=b.val?a.val>b.val:a.ord<b.ord;
}

int main() {
  freopen("small.in","r",stdin);
  freopen("small.out","w",stdout);
  int T,t,n,i,j,k;
  scanf("%d",&T);
  for (t=1;t<=T;t++) {
    scanf("%d",&n);
    for (i=0;i<n;i++) {
      scanf("%d",&j);
    }
    for (i=0;i<n;i++) {
      scanf("%d",&a[i].val);
      a[i].ord=i;
    }
    std::sort(a,a+n,cmp);
    printf("Case #%d: ",t);
    for (i=0;i<n;i++)
      printf("%d ",a[i].ord);
    putchar(10);
  }
  return 0;
}
