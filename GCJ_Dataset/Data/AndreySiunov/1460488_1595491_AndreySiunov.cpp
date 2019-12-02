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
	int n,s,p,t[113];
	cin>>n>>s>>p;
	for (int i=1;i<=n;i++){
		cin>>t[i];
	}
	int a[113][113];
	memset(a,128,sizeof(a));
	a[0][0]=0;
	for (int i=1;i<=n;i++){
		for (int b1=0;b1<=10;b1++){
			for (int b2=max(0,b1-2);b2<=min(10,b1+2);b2++){
				for (int b3=max(0,b1-2);b3<=min(10,b1+2);b3++){
					if (aabs(b3-b2)<=2 && b1+b2+b3==t[i]){
						if (max(max(aabs(b1-b2),aabs(b1-b3)),aabs(b2-b3))<=1){
							if (max(max(b1,b2),b3)>=p){
								for (int j=0;j<=i;j++){
									a[i][j]=max(a[i][j],a[i-1][j]+1);
								}
							}
							else{
								for (int j=0;j<=i;j++){
									a[i][j]=max(a[i][j],a[i-1][j]);
								}
							}
						}
						else{
							if (max(max(b1,b2),b3)>=p){
								for (int j=1;j<=i;j++){
									a[i][j]=max(a[i][j],a[i-1][j-1]+1);
								}
							}
							else{
								for (int j=1;j<=i;j++){
									a[i][j]=max(a[i][j],a[i-1][j-1]);
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<a[n][s];
	cout<<endl;
}

int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);

	//begin code
	//ios::sync_with_stdio(0);
	int t;
	cin>>t;
	for (int ct=1;ct<=t;ct++){
		cout<<"Case #"<<ct<<": ";
		solve();
	}
	//end code

	return 0;
}