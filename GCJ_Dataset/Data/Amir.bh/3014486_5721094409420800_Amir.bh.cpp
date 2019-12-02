#pragma comment(linker,"/STACK:268435456")
#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <sstream>
#include <bitset>
#include <iterator>
#include <list>
#include <ctime>
#include <functional>

#define FR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,c,n) for(int (i)=(c);(i)<(n);(i)++)
#define REP(it,v,cont) for((cont)::iterator (it)=(v).begin();(it)!=(v).end();++(it))
#define CLR(a,c) memset((a),(c),sizeof (a))
#define ALL(v) (v).begin(),(v).end()
#define VCPRINT(v) for(int iii = 0;iii < (v).size();iii++) cout<<(v)[iii]<<" ";cout<<endl;
#define SETPRINT(v,cont) for((cont)::iterator iiit = (v).begin();iiit != (v).end();iiit++) cout<<*iiit<<" ";cout<<endl;

bool ascending (int i,int j) { return (i<j); }
bool descending (int i,int j) { return (i>j); }

typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define PULI pair<unsigned long long,int>
#define PIL pair<int,long long>
#define PSI pair<string,int>
#define PSS pair<string,string>
#define PDD pair<double,double>
#define PIB pair<int,bool>
typedef long double ld;

using namespace std;

multiset<int,greater<int> > S;
int A[100*100+100];
int B[100*100+100];
map<int,int> mp;

bool check(int n)
{
	int mx = max_element(B,B+n)-B;
	int it = 1;
	while(it < mx){
		if(B[it]<=B[it-1]) return false;
		it++;
	}
	it++;
	while(it < n){ if(B[it]>=B[it-1]) return false;it++;}
	return true;
}

int sgn(int n)
{
	return n==0?n:(n>0?1:-1);
}


int main()
{
	ifstream cin("a.in");
	ofstream cout("a.out");
	int T;cin>>T;
	FOR(_,1,T+1)
	{
		mp.clear();
		int n;cin>>n;
		FR(i,n){ cin>>A[i];B[i]=A[i];mp[A[i]]=i;}
		sort(B,B+n);
		int ans = INT_MAX;
		do{
			if(check(n))
			{
				int dis = 0;
				FR(i,n)
					FOR(j,i+1,n)
						if(sgn(mp[B[i]]-mp[B[j]])!=sgn(i-j))
							dis++;
				ans = min(ans,dis);
			}
		}while(next_permutation(B,B+n));
		cout<<"Case #"<<_<<": ";
		cout<<ans<<endl;
	}
}