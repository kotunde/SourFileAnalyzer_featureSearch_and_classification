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
	long long n,w,l;
	cin>>n>>w>>l;
	long long r[1013];
	for (int i=0;i<n;i++){
		cin>>r[i];
	}
	//sort(r,r+n);
	long long x[1013], y[1013];
	long long down=-2000000000;
	for (int i=0;i<n;){
		long long ddown=down;
		if (i==n-1 || r[i]+r[i+1]>w){
			x[i]=0;
			y[i]=max(down,-r[i])+r[i];
			ddown=max(ddown,y[i]+r[i]);
			i++;
		}
		else{
			int left = -r[i];
			x[i]=0;
			y[i]=max(down,-r[i])+r[i];
			ddown=max(ddown,y[i]+r[i]);
			x[i+1]=r[i]+r[i+1];
			y[i+1]=max(down,-r[i+1])+r[i+1];
			ddown=max(ddown,y[i+1]+r[i+1]);
			long long j=i+2,ss=r[i]+r[i+1];
			while (j<n && w>=ss+r[j]+r[j-1]){
				ss+=r[j]+r[j-1];
				x[j]=ss;
				y[j]=max(down,-r[j])+r[j];
				ddown=max(ddown,y[j]+r[j]);
				j++;
			}
			i=j;
		}
		down=ddown;
	}
	for (int i=0;i<n;i++){
		cout<<x[i]<<' '<<y[i]<<' ';
		if (y[i]>l || y[i]<0 || x[i]<0 || x[i]>w){
			cout<<"ERROR!";
		}
		for (int j=0;j<n;j++){
			if (i!=j){
				if ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<(r[i]+r[j])*(r[i]+r[j])){
					cout<<"ERROR!"<<i<<' '<<j<<' ';
				}
			}
		}
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