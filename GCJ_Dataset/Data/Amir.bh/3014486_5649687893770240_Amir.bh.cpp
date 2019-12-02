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

map<int,int,greater<int> > mp;

string s[10];

int main()
{
	ifstream cin("a.in");
	ofstream fout("a.out");
	int T;cin>>T;
	FOR(_,1,T+1)
	{
		mp.clear();
		int n,m;cin>>n>>m;
		FR(i,n)
			cin>>s[i];
		FR(mask,pow(m,n))
		{
			int cans = 0;
			int A[10];
			set<string> S[5];
			FR(i,5){ S[i].clear();}
			bool part[5];
			CLR(part,0);


			int cur = mask;
			FR(i,n)
			{
				A[i]=cur%m;
				part[A[i]]=true;
				cur/=m;
			}
			bool flag = true;
			FR(i,m) if(!part[i]) flag = false;
			
			if(!flag) continue;

			FR(i,n)
			{
				FR(j,s[i].size()+1){
					S[A[i]].insert(s[i].substr(0,j));
				}
			}
			FR(i,m){
				cans += S[i].size();
				flag = flag && S[i].size();
			}
			
			mp[cans]++;
		}



		fout<<"Case #"<<_<<": ";
		fout<<mp.begin()->first<<" "<<mp.begin()->second<<endl;
	}
}