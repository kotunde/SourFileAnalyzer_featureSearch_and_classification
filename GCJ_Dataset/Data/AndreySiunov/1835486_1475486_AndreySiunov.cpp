#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <list>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>
#include <list>
#include <set>
#include <stack>
#include <bitset>
#include <ctime>

#pragma comment(linker, "/STACK:256000000")

#define EPS 1e-7
#define PI 3.1415926535897932384626433832795

using namespace std;

int aabs(int a){
	if (a<0) return -a;
	return a;
}

void solve(){
	int n;
	cin>>n;
	pair<int,int> a[1013];
	for (int i=0;i<n;i++){
		cin>>a[i].second;
		a[i].second=n-1-i;
	}
	for (int i=0;i<n;i++){
		cin>>a[i].first;
	}
	sort(a,a+n);
	for (int i=n-1;i>=0;i--){
		cout<<n-1-a[i].second<<' ';
	}
	cout<<endl;
}

int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);

	// begin code
	//ios::sync_with_stdio(0);
	int t;
	cin>>t;
	for (int i=1;i<=t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	//end code

	return 0;
}
