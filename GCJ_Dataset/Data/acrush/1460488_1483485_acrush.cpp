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

#define LENGTH(X) ((int)(X.length()))

string s1[]={"ejp mysljylc kd kxveddknmc re jsicpdrysi",
			 "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
			 "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
string s2[]={"our language is impossible to understand",
			 "there are twenty six factorial possibilities",
			 "so it is okay if you want to just give up"};

int p[26];
char s[1024];

void init()
{
	memset(p,255,sizeof(p));
	for (int i=0;i<3;i++) for (int j=0;j<LENGTH(s1[i]);j++)
		if (s1[i][j]!=' ')
			p[s1[i][j]-'a']=s2[i][j]-'a';
	bool used[26];
	memset(used,false,sizeof(used));
	for (int i=0;i<26;i++) if (p[i]>=0) used[p[i]]=true;
	for (int i=0;i<26;i++) if (p[i]<0)
		for (int k=25;k>0;k--) if (!used[k])
		{
			p[i]=k;
			used[k]=true;
			break;
		}
}
int main()
{
	init();
	freopen("A.in","r",stdin);
	//freopen("A-small-attempt0.in","r",stdin); freopen("A-small-attempt0.out","w",stdout);
	//freopen("A-small-attempt0.in","r",stdin); freopen("A-small-attempt0.out","w",stdout);
	int testcase;
	gets(s);
	sscanf(s,"%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		gets(s);
		printf("Case #%d: ",case_id);
		for (int i=0;s[i];i++) 
			if (s[i]!=' ')
				s[i]='a'+p[s[i]-'a'];
		printf("%s\n",s);
	}
	return 0;
}
