#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#include <stdlib.h>
#include <sstream>
#include <ctime>
#include <fstream>
using namespace std;
 
using namespace std;
 
#define INF 1000000000
#define PI acos(-1.0)
#define MP make_pair
long double EPS=1e-10;
#define MOD 1000000007 

pair<int,int> a[10000];
int d[10000];

void solve(){
	int n,m;
	scanf("%d",&n);
	for (int i=0; i<n; i++){
		scanf("%d%d",&a[i].first,&a[i].second);
		d[i]=0;
	}
	scanf("%d",&m);
	d[0]=a[0].first;


	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			if (a[j].first-a[i].first>d[i]) continue;

			d[j]=max(d[j],min(a[j].second,abs(a[j].first-a[i].first)));
		}
	}

	for (int i=0; i<n; i++){
		if (abs(m-a[i].first)<=d[i]){
			cout<<"YES"<<endl;
			return;
		}
	}

	cout<<"NO"<<endl;

}

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int tt;
	cin>>tt;
	for (int t=1; t<=tt; t++){
		cerr<<"Case #"<<t<<endl;
		cout<<"Case #"<<t<<": ";
		solve();
	}

}