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

int a[20];

map<int,long long> d[21];

void solve(){

	int n;
	cin>>n;

	for (int i=0; i<n; i++){
		cin>>a[i];
	}

	for (int i=0; i<n; i++){
		d[i].clear();
	}

	d[0][0]=0;
	for (int i=0; i<n; i++){
		for (map<int,long long>::iterator it=d[i].begin(); it!=d[i].end(); it++){
			d[i+1][it->first]=it->second*3;
			d[i+1][it->first-a[i]]=it->second*3+1;
			d[i+1][it->first+a[i]]=it->second*3+2;
		}
	}
	cout<<endl;

	if (d[n].find(0)!=d[n].end()){
		vector<int>A,B;
		long long x=d[n][0];

		for (int i=0; i<n; i++){
			if (x%3==1) A.push_back(a[n-i-1]);
			if (x%3==2) B.push_back(a[n-i-1]);
			x/=3;
		}

		for (int i=0; i<A.size(); i++){
			cout<<A[i]<<' ';
		}
		cout<<endl;
		for (int i=0; i<B.size(); i++){
			cout<<B[i]<<' ';
		}
		cout<<endl;
	}
	else cout<<"Impossible"<<endl;

}

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int tt;
	cin>>tt;
	for (int t=1; t<=tt; t++){
		cout<<"Case #"<<t<<": ";
		solve();
	}

}