#include <cstdio>
#include <cstring>
const char c[26]={
  'y','h','e','s','o','c','v','x','d',
  'u','i','g','l','b','k','r','z','t',
  'n','w','j','p','f','m','a','q'
};
int main() {
  //freopen("in.in","r",stdin);
  //freopen("out.txt","w",stdout);
  int T,l,i,t;
  scanf("%d\n",&T);
  for (t=1;t<=T;t++) {
    char s[1024];
    gets(s);
    l=strlen(s);
    for (i=0;i<l;i++)
      if ('a'<=s[i]&&s[i]<='z')
        s[i]=c[s[i]-'a'];
    printf("Case #%d: %s\n",t,s);
  }
  return 0;
}
