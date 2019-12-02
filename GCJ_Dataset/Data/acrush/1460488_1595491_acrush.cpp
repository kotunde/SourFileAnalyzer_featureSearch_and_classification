#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}

const int maxn=128;
int n,m,p,s[maxn];
int b[maxn][2][2],f[maxn][maxn];

int solve(int d,int l)
{
	if (d==n) return (l==0)?10000:0;
	int &ret=f[d][l];
	if (ret>=0) return ret;
	ret=0;
	for (int x=0;x<2;x++) for (int y=0;y<2;y++) if (l-x>=0 && b[d][x][y])
		checkmax(ret,solve(d+1,l-x)+y);
	return ret;
}
int main()
{
	freopen("B.in","r",stdin);
	//freopen("B-small-attempt0.in","r",stdin); freopen("B-small-attempt0.out","w",stdout);
	//freopen("B-small-attempt1.in","r",stdin); freopen("B-small-attempt1.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		scanf("%d%d%d",&n,&m,&p);
		for (int i=0;i<n;i++) scanf("%d",&s[i]);
		memset(b,0,sizeof(b));
		for (int s0=0;s0<=10;s0++) for (int s1=s0;s1<=10 && s1<=s0+2;s1++) for (int s2=s1;s2<=10 && s2<=s0+2;s2++) 
			for (int i=0;i<n;i++) if (s[i]==s0+s1+s2)
				b[i][(int)(s2-s0==2)][(int)(s2>=p)]=1;
		memset(f,255,sizeof(f));
		printf("Case #%d: %d\n",case_id,solve(0,m)-10000);
	}
	return 0;
}
