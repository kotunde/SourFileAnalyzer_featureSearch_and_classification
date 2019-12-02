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

long long n;
long long a[2013];
long long b[2013];
long long m[2013];

bool f(long long l, long long r){
	if (r-l<2){
		return 1;
	}
	long long last=l;
	bool qq=0;
	for (long long i=l+1;i<r;i++){
		if (a[i]>r){
			return 0;
		}
		if (a[i]==r){
			qq=1;
			b[i]=m[i];
			for (long long j=last+1;j<i;j++){
				m[j]=b[i]+((b[r]-b[i])*(j-i))/(r-i)-3;
			}
			bool pp=f(last,i);
			if (!pp){
				return 0;
			}
			last=i;
		}
	}
	if (!qq) return 0;
	bool pp=f(last,r);
	if (!pp){
		return 0;
	}
	return 1;
}

void solve(){
	cin>>n;
	for (long long i=0;i<n-1;i++){
		cin>>a[i];
		a[i]--;
		if (a[i]<=i){
			cout<<"Impossible";
			cout<<endl;
			return;
		}
	}
	memset(b,255,sizeof(b));
	b[0]=1000000000;
	for (long long i=0;i<n-1;){
		long long t=a[i];
		if (i>=t){
			cout<<"Impossible";
			cout<<endl;
			return;
		}
		b[t]=b[i];
		for (long long j=i+1;j<t;j++){
			m[j]=b[t]-1;
		}
		bool pp=f(i,t);
		if (!pp){
			cout<<"Impossible";
			cout<<endl;
			return;
		}
		i=t;
	}
	for (long long i=0;i<n;i++){
		cout<<b[i]<<' ';
	}
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