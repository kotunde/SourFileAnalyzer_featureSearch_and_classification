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

int gcd(int a, int b){
	while (a>0 && b>0){
		if (a>b){
			a%=b;
		}
		else{
			b%=a;
		}
	}
	return a+b;
}

void solve(){
	int n;
	int a[10013], b[10013];
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	int c;
	cin>>c;
	int d[10013];
	d[0]=min(a[0],b[0]);
	for (int i=1;i<n;i++){
		d[i]=0;
	}
	for (int i=0;i<n;i++){
		if (d[i]<1000000013){
			for (int j=i+1;j<n;j++){
				if (a[j]-a[i]<=d[i]){
					d[j]=min(b[j],max(d[j],a[j]-a[i]));
				}
				else{
					break;
				}
			}
		}
	}
	for (int i=0;i<n;i++){
		if (c-a[i]<=d[i]){
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO";
	cout<<endl;
	return;
}

int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);

	// begin code
	//ios::sync_with_stdio(0);
	int t;
	cin>>t;
	char s[100];
	cin.getline(s,100);
	for (int i=1;i<=t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	//end code

	return 0;
}