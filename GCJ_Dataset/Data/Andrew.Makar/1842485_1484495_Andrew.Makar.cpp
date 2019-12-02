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


int A[8000000];
int a[10];

void add(int i,int l,int r,int x,int v){
	if (l==x && r==x){
		A[i]=v;
		return;
	}

	int m=(r+l)/2;
	if (x<=m) add(i*2+1,l,m,x,v);
	else add(i*2+2,m+1,r,x,v);
	A[i]=max(A[i*2+1],A[i*2+2]);
}

int get(int i,int l,int r,int l1,int r1){
	if (l==l1 && r==r1) return A[i];

	if (l1>r1) return 0;

	int m=(r+l)/2;

	int res=0;

	res=max(res,get(i*2+1,l,m,l1,min(m,r1)));
	res=max(res,get(i*2+2,m+1,r,max(m+1,l1),r1));

	return res;
}

pair<int,int> aa[10];
int n,w,h;

int check(){
	for (int i=0; i<n; i++){
		if (aa[i].first<0 || aa[i].second<0 || aa[i].first>w || aa[i].second>h){ 
			cerr<<aa[i].first<<' '<<aa[i].second<<endl;
			return 1;
		}
	}

	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			long long d=(aa[i].first-aa[j].first)*(long long)(aa[i].first-aa[j].first) + (aa[i].second-aa[j].second)*(long long)(aa[i].second-aa[j].second);
			long long D=(a[i]+a[j])*(long long)(a[i]+a[j]);
			if (d<D){
				return 2;
			}
		}
	}

	return 0;
}

void solve(){

	cin>>n>>w>>h;

	int s=0;

	for (int i=0; i<n; i++){
		cin>>a[i];
	}

	if (w>=2000000){
		int s=0;
		for (int i=0; i<n; i++){
			if (i!=0) s+=a[i];
			aa[i]=MP(s,0);
			cout<<s<<' '<<0<<' ';
			s+=a[i];
		}
		int res=check();
		cout<<endl;
		if (res==0) return;
		cerr<<res<<endl;
		return;
	}

	for (int i=0; i<8000000; i++){
		A[i]=0;
	}
	
	

	for (int i=0; i<n; i++){
		bool ok=0;
		for (int j=0; j<=w; j++){

			int L=max(0,j-a[i]),R=min(w,j+a[i]);

			int mm=get(0,0,2000000,L,R);
			if (mm+a[i]<=h || mm==0){

				if (mm==0) mm=-a[i];

				cout<<j<<' '<<mm+a[i];
				if (i!=n-1) cout<<' ';

				aa[i]=MP(j,mm+a[i]);

				if (L==0) L=-1;
				if (R==w) R=w+1;

				for (int k=L+1; k<R; k++){
					add(0,0,2000000,k,mm+2*a[i]);
				}
				ok=1;
				break;
			}
		}
		if (!ok) cerr<<"aaa";
	}

	cout<<endl;

	int res=check();
	if (res==0) return;
	cerr<<res<<endl;


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