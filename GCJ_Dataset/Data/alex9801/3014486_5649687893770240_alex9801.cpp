#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>

const int PROB_NUM=6;

typedef std::set<long long> S;

inline long long ms(char* arr,int l)
{
	int i;
	long long r=0;
	for(i=0;i<l;i++)
	{
		r*=27;
		r+=arr[i]-'A'+1;
	}
	return r;
}

S tri[4];
char arr[8][11];
bool chk[4];
int sta[8];
int m,n;
int mx,cnt;

void f(int x)
{
	if(x==m)
	{
		int t=0,i,j;
		for(i=0;i<n;i++)
			chk[i]=0;
		for(i=0;i<m;i++)
			chk[sta[i]]=1;
		for(i=0;i<n;i++)
			if(!chk[i])
				return;
		for(i=0;i<n;i++)
			tri[i].clear();
		for(i=0;i<m;i++)
			for(j=0;j==0||arr[i][j-1];j++)
				tri[sta[i]].insert(ms(arr[i],j));
		for(i=0;i<n;i++)
			t+=tri[i].size();
		if(t>mx)
		{
			mx=t;
			cnt=1;
		}
		else if(t==mx)
			cnt++;
		return;
	}
	int i;
	for(i=0;i<n;i++)
	{
		sta[x]=i;
		f(x+1);
	}
}

void pre_process()
{

}

void process()
{
	mx=0;
	cnt=0;
	int i;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
		scanf("%s",arr[i]);
	f(0);
	printf("%d %d\n",mx,cnt);
}

int main()
{
	char in[10]="0.in";
	char out[10]="0.out";
	in[0]=PROB_NUM+'0';
	out[0]=PROB_NUM+'0';
	freopen(in,"r",stdin);
	freopen(out,"w",stdout);
	pre_process();
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		process();
	}
	return 0;
}