
//Written by Alex H Ahmadi (alex@hamedahmadi.com)

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
using namespace std;

#define FOR(i,n) for (int i=0;i<(n);i++)
#define FORIT(it,s) for (__typeof(s.begin()) it=s.begin(); it!=s.end(); ++it)
#define ALL(x) (x).begin(),(x).end()
#define P(x) cerr<<#x<<" = "<<x<<endl
#define pb push_back

#define zer(x) memset(x,0,sizeof(x));
#define isin(x,s) (s.find(x)!=s.end())

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;

const int maxn=220;

struct Food {
  ll time;
  ll price;
  bool operator < (const Food &o) const {
	return price<o.price;
  }
  bool isbetter(const Food &o) {
	return time>=o.time && price<=o.price;
  }
} a[maxn];

int n;

ll deliv;

bool canlive(ll days, ll cash) {
  //cerr<<"Testing "<<days<<" days"<<endl;
  if (days>cash) return 0;

  if (days==0) return 1;
  if (days==1) return deliv+a[0].price<=cash;

  //P(deliv);
  ll prevdays=0;
  ll prevcost=0;//deliv;
  for (int i=0;i<n;i++) {
	if (prevdays>days) break;

	ll avail=a[i].time-prevdays; //max we can take

	//ll mindeliv=
	ll mind=(days+a[i].time-1)/a[i].time; //min # of deliveries
	ll maxd;
	if (prevdays==0) maxd=days;
	else maxd=days/prevdays;
	if (mind>maxd) {
	  cerr<<"BAD MIND MAXD,  "<<mind<<" "<<maxd<<endl;
	  goto next;
	}
	//P(i);
	//P(mind);
	//P(maxd);
	
	for (ll d=mind; d<=maxd; d+=maxd-mind) {
	  ll cost=0;
	  //if (deliv < cash/d) continue;

	  //cerr<<"going with d = "<<d<<endl;
	  cost=0;
	  //P(cost);
	  cost+=d*deliv;
	  //if (cost>cash) continue;
	  //P(cost);
	  
	  cost+=d*prevcost;
	  //if (cost>cash) continue;
	  //P(cost);

	 
	  ll left=days-prevdays*d;
	  cost+=left*a[i].price;
	  //P(left); P(a[i].price);
	  //if (cost>cash) continue;
	  //P(cost);
	  if (cost<=cash) return 1;

	  if (d==maxd) break;
	}

  next:;
	prevdays=a[i].time;
	//UPDATE prevcost
	prevcost+=avail*a[i].price; //TODO: overflow
  }

  return 0;
}

void clear() {
}

void solve(int cnum) {
  cout<<"Case #"<<cnum<<": ";

  ll m;
  cin>>m>>deliv>>n;
  FOR (i,n) cin>>a[i].price>>a[i].time;

  FOR (i,n) a[i].time++;

  //elim extra
  FOR (i,n) {
	FOR (j,n) 
	  if (i!=j && a[j].isbetter(a[i])) {
		a[j]=a[n-1];
		n--;
		i--;
		break;
	  }
  }
  sort(a,a+n);
  
  ll lo=0;
  ll hi=m;

  while (lo<hi) {
	ll mid=lo+(hi-lo+1)/2;
	if (canlive(mid, m))
	  lo=mid;
	else hi=mid-1;
  }
  cout<<lo<<endl;  
}

int main() {
  int nt;
  cin>>nt;
  for (int cnum=1; cnum<=nt; cnum++) {
	clear();
	solve(cnum);
  }
  return 0;
}
