#include <fstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
  ifstream f("input.txt");
  ofstream w("output.txt");
  int T;
  f>>T;
  int N,X;
  int a[10005];
  bool s[10005];
  for (int ti=1;ti<=T;ti++)
  {
    f>>N>>X;
    int count=0;
    memset(s,0, N*sizeof(bool));
    for (int i=0;i<N;i++)
      f>>a[i];
    sort(a,a+N);
    for (int i=N-1;i>=0;i--){
      if (s[i]) continue;
      int j=-1;
      int maxn=-1;
      while (j+1<i&&a[i]+a[j+1]<=X)
      {
	if (s[j+1]==0) maxn=j+1;
	j++;
      }
      if (maxn!=-1)
	s[maxn]=1;
      s[i]=1;
      count++;
    }
    w<<"Case #"<<ti<<": "<<count<<endl;
    
  }
  return 0;
}