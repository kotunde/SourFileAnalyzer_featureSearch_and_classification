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

int c[200][200];
int h[200][200];

int n,m,H;

struct P{
	int x,y;
	double v1,v2;

	P():x(),y(),v1(),v2(){}
	P(int _x,int _y,double _v1,double _v2):x(_x),y(_y),v1(_v1),v2(_v2){}
};

vector<P>g[200][200];

int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

pair<double,double> ok(int x1,int y1,int x2,int y2){
	if (x1<0 || x1>=n || y1<0 || y1>=m || x2<0 || x2>=n || y2<0 || y2>=m) return MP(-INF,-INF);

	int c1=c[x1][y1],c2=c[x2][y2];
	int h1=h[x1][y1],h2=h[x2][y2];

	if (c2-h1<50) return MP(-INF,-INF);
	if (c1-h2<50) return MP(-INF,-INF);
	if (c1-h1<50) return MP(-INF,-INF);
	if (c1-h2<50) return MP(-INF,-INF);

	int C=min(c1,c2);
	int HH=C-50;

	if (HH>=H) return MP(0,0);
	double first=(H-HH)/10.0;
	double second;
	if (HH-h1>=20) second=1;
	else second=10;

	return MP(first,second);
}

bool u[200][200];
double D[200][200];

void solve(){

	
	scanf("%d%d%d",&H,&n,&m);
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%d",&c[i][j]);
		}
	}

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%d",&h[i][j]);
			g[i][j].clear();
		}
	}

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			for (int k=0; k<4; k++){
				int x=i+d[k][0],y=j+d[k][1];

				pair<double,double> A=ok(i,j,x,y);
				if (A.first>-47) g[i][j].push_back(P(x,y,A.first,A.second));
			}
		}
	}

	/*for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cerr<<endl<<"=="<<i<<' '<<j<<' '<<g[i][j].size()<<endl;
			for (int k=0; k<g[i][j].size(); k++){
				cerr<<g[i][j][k].x<<' '<<g[i][j][k].y<<' '<<g[i][j][k].v1<<' '<<g[i][j][k].v2<<endl;
			}
			cerr<<endl;
		}
	}*/


	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			u[i][j]=0;
			D[i][j]=INF;
		}
	}

	D[0][0]=0;

	for (;;){
		double mm=INF;
		int pp1=-1,pp2=-1;
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				if (u[i][j]) continue;

				if (D[i][j]<mm){
					mm=D[i][j];
					pp1=i;
					pp2=j;
				}
			}
		}

		if (pp1==-1)break;

		u[pp1][pp2]=1;

		for (int i=0; i<g[pp1][pp2].size(); i++){
			int x=g[pp1][pp2][i].x,y=g[pp1][pp2][i].y;
			double v1=g[pp1][pp2][i].v1;

			double t=max(mm,v1);

			double v2;

			if (t<EPS) v2=0;
			else{
				double HH=H-t*10;
				if (HH-h[pp1][pp2]+EPS>20) v2=1;
				else v2=10;
			}

			D[x][y]=min(D[x][y],t+v2);
		}
	}

/*	cout<<endl;

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			printf("%.2f ",D[i][j]);
		}
		printf("\n");
	}*/

	printf("%.9f\n",D[n-1][m-1]);
	



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