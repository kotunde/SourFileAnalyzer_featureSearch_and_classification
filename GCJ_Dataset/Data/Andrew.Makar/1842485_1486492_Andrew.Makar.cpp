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

int a[100];
int h[100];
int n;

bool check(){
	for (int i=0; i<n-1; i++){
		int r=i+1;
		for (int j=i+2; j<n; j++){
			long long a1=j-i;
			long long a2=r-i;

			long long b1=h[j]-h[i];
			long long b2=h[r]-h[i];

			if (b1*a2<=a1*b2) continue;
			r=j;
		}
		if (r!=a[i]) return 0;
	}
	return 1;
}

void solve(){
	
	cin>>n;
	for (int i=0; i<n-1; i++){
		cin>>a[i];
		a[i]--;
	}

	int it=0;

	do{
		it++;
		if (it>10000000){
			cout<<"Impossible"<<endl;
			return;
		}
		for (int i=0; i<n; i++){
			h[i]=(rand()*rand()*(long long)rand())% 10000001;
		}


	} while(!check());


	for (int i=0; i<n; i++){
		cout<<h[i];
		if (i!=n-1) cout<<' ';
	}
	cout<<endl;


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