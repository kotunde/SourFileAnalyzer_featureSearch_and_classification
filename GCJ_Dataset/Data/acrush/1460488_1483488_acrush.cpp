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


int n;
int ga[3000000],gb[3000000];

void init()
{
	n=0;
	for (int e=1,a=1;a<=2000000;a++)
	{
		if (e==a) e*=10;
		for (int p10=10;p10<=a;p10*=10)
		{
			int b=(a%p10)*(e/p10)+a/p10;
			if (a<b && b<e && b<=2000000) ga[n]=a,gb[n]=b,n++;
		}
	}
}
int main()
{
	//freopen("C.in","r",stdin);
	freopen("C-small-attempt0.in","r",stdin); freopen("C-small-attempt0.out","w",stdout);
	//freopen("C-small-attempt1.in","r",stdin); freopen("C-small-attempt1.out","w",stdout);
	//freopen("C-large.in","r",stdin); freopen("C-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	init();
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int ret=0;
		for (int i=0;i<n;i++) if (ga[i]>=a && gb[i]<=b) ret++;
		printf("Case #%d: %d\n",case_id,ret);
	}
	return 0;
}
