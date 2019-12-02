//TAG : 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<algorithm>
#include <climits>
using namespace std;

#define rep(i,n)	for(int (i)=0;(i)<(n);(i)++)
#define repd(i,n)	for(int (i)=(n)-1;(i)>=0;(i)--)
#define REP(i,n) for (int (i)=0,_n=(n); (i) < _n; (i)++)
#define FOR(i,a,b) for (int _b=(b), (i)=(a); (i) <= _b; (i)++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset((x),0,sizeof(x));
#define CLEARA(x) memset(&(x),0,sizeof(x));
#define FILL(x,v) memset((x),(v),sizeof(x));
#define FILLA(x,v) memset(&(x),(v),sizeof(x));

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
//const double pi = acos(-1.0);
#define EPS 1e-9

int main()
{
	char grid[50][51];

	int test_case;
	scanf("%d",&test_case);
	FOR(t,1,test_case){
		int row,col,mines;
		scanf("%d %d %d",&row,&col,&mines);
		printf("Case #%d:\n",t);
		//CLEAR grid
		rep(i,row){
			rep(j,col)grid[i][j]='.';
			grid[i][col]=0;
		}
		bool ispossible=true;
		if(row==1){
			FORD(i,col-1,col-mines)grid[0][i]='*';
		}else if(col==1){
			FORD(i,row-1,row-mines)grid[i][0]='*';
		}else{
			//R,C>=2
			int empty=row*col-mines;
			if(mines==0){
			}else if(empty==1){
				rep(r,row)rep(c,col)if(r>=1 || c>=1)grid[r][c]='*';
			}else if(empty<4 || empty==5 || empty==7){
				ispossible=false;//impossible
			}else if(empty==4){
				rep(r,row)rep(c,col)if(r>=2 || c>=2)grid[r][c]='*';
			}else if(row==2 || col==2){
				if(empty%2==1)
					ispossible=false;//impossible
				else if(row==2){
					FOR(c,col-mines/2,col-1)rep(r,row)grid[r][c]='*';
				}else if(col==2){
					FOR(r,row-mines/2,row-1)rep(c,col)grid[r][c]='*';
				}
			}else{//R,C>=3
				//empty>=9 or 6, 8
				if(row<=col){
					//3*n의 형태로 먼저 만들자.
					int r=row-1;
					for(;r>=3 && mines>=col;r--,mines-=col)rep(c,col)grid[r][c]='*';
					if(r>=3){
						REP(c,min(mines,col-2))grid[r][c]='*';
						if(mines>(col-2))grid[r-1][2]='*';
					}else{
						int c=col-1;
						for(;c>=2 && mines>=3;c--,mines-=3)rep(r,3)grid[r][c]='*';
						if(mines==1)grid[2][c]='*';
						else if(mines==2)grid[2][c]='*',grid[2][c-1]='*';
					}
				}else{
					//n*3의 형태로 만들자.
					int c=col-1;
					for(;c>=3 && mines>=row;c--,mines-=row)rep(r,row)grid[r][c]='*';
					if(c>=3){
						REP(r,min(mines,row-2))grid[r][c]='*';
						if(mines>(row-2))grid[2][c-1]='*';
					}else{
						int r=row-1;
						for(;r>=2 && mines>=3;r--,mines-=3)rep(c,3)grid[r][c]='*';
						if(mines==1)grid[r][2]='*';
						else if(mines==2)grid[r][2]='*',grid[r-1][2]='*';
					}
				}
			}
		}
		if(ispossible){
			grid[0][0]='c';
			rep(i,row)puts(grid[i]);
		}else
			puts("Impossible");
	}
	return 0;
}