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


vector<ld> V;

int main()
{
	ifstream cin("a.in");
	ofstream cout("a.out");
	int T;cin>>T;
	cout<<setprecision(7)<<fixed;
	FOR(_,1,T+1)
	{
		V.clear();
		ld C,F,X;cin>>C>>F>>X;
		int it = 0;
		ld sum = 0;
		ld last = 1;

		ld MIN = X/2.;

		while(last>1e-6)
		{
			ld ans = sum + X/(2+it*F);
			if(ans > MIN) break;
			MIN = ans;
			last = C/(2.+(it++)*F);
			sum += last;
		}


		cout<<"Case #"<<_<<": ";
		cout<<MIN;
		cout<<endl;
	}
}