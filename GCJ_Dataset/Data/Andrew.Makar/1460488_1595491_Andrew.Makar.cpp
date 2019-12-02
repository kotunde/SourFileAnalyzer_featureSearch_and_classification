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
double EPS=1e-7;
#define MOD 1000000007 

int a[100];
int d[200][200];

bool c0(int x,int p){
	for (int i=0; i<=x; i++){
		for (int j=i; j<=x; j++){
			for (int k=j; k<=x; k++){

				if (j-i>2 || k-j>2 || k-i>2) continue;

				if (i+j+k==x && i<p && j<p && k<p && (i-j<2 && k-j<2 && k-i<2)) return 1;
			}
		}
	}

	return 0;
}

bool c1(int x,int p){
	for (int i=0; i<=x; i++){
		for (int j=i; j<=x; j++){
			for (int k=j; k<=x; k++){

				if (j-i>2 || k-j>2 || k-i>2) continue;

				if (i+j+k==x && i<p && j<p && k<p && (i-j==2 || k-j==2 || k-i==2)) return 1;
			}
		}
	}

	return 0;
}

bool c2(int x,int p){
	for (int i=0; i<=x; i++){
		for (int j=i; j<=x; j++){
			for (int k=j; k<=x; k++){

				if (j-i>2 || k-j>2 || k-i>2) continue;

				if (i+j+k==x && (i>=p || j>=p || k>=p) && (i-j<2 && k-j<2 && k-i<2)) return 1;
			}
		}
	}

	return 0;
}

bool c3(int x,int p){
	for (int i=0; i<=x; i++){
		for (int j=i; j<=x; j++){
			for (int k=j; k<=x; k++){

				if (j-i>2 || k-j>2 || k-i>2) continue;

				if (i+j+k==x && (i>=p || j>=p || k>=p) && (i-j==2 || k-j==2 || k-i==2)) return 1;
			}
		}
	}

	return 0;
}



int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int tt;
	cin>>tt;
	
	for (int t=1; t<=tt; t++){
		int n,s,p;
		cin>>n>>s>>p;
		for (int i=0; i<n; i++){
			cin>>a[i];
		}

		for (int i=0; i<100; i++){
			for (int j=0; j<100; j++){
				d[i][j]=-INF;
			}
		}

		d[0][0]=0;
		
		for (int i=0; i<n; i++){
			for (int j=0; j<=s; j++){
				if (c0(a[i],p)) d[i+1][j]=max(d[i+1][j],d[i][j]);
				if (c1(a[i],p)) d[i+1][j+1]=max(d[i+1][j+1],d[i][j]);
				if (c2(a[i],p)) d[i+1][j]=max(d[i+1][j],d[i][j]+1);
				if (c3(a[i],p)) d[i+1][j+1]=max(d[i+1][j+1],d[i][j]+1);
			}
		}

		cout<<"Case #"<<t<<": ";

		cout<<d[n][s]<<endl;


	}
	
	


}