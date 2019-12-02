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

int a[200];
int n;
int S;

bool ok(double x,int k){
	double s=(x-a[k])/S;
	for (int i=0; i<n; i++){
		if (i==k) continue;
		if (a[i]>x) continue;
		s+=(x-a[i])/S;
	}

	if (s+EPS<1) return 1;
	return 0;
}

void solve(){

	cin>>n;
	S=0;
	for (int i=0; i<n; i++){
		cin>>a[i];
		S+=a[i];
	}

	for (int i=0; i<n; i++){
		double l=0,r=1;
		for (int it=0; it<100; it++){
			double m=(r+l)/2;
			if (ok(a[i]+m*S,i))  l=m;
			else r=m;
		}

		printf("%.9f ",l*100);
	}
	printf("\n");


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