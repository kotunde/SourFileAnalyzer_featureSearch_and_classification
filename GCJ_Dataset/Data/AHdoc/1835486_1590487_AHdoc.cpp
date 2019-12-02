#include <iostream>
#include <cstdio>
#include <cstring>
#define MP make_pair
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fi(i,a,b) for(int j=a;j>=b;j--)
using namespace std ;

const int MaxN = 6009 ;
const int MaxM = 10009 ;

int N , M ;
int X[MaxM] , Y[MaxM] ;
pair<int,int> Corner[10] ;
bool Bound[MaxN*2][MaxN*2] , vis[MaxN*2][MaxN*2] , vis_[MaxN*2][MaxN*2] , A[MaxN*2][MaxN*2] ;

void Init() {
	cin >> N >> M ;
	// cout << N << " " << M << "\n" ;
	fo(i,1,M) cin >> X[i] >> Y[i] ;
	// if ( N <= 5 ) { fo(i,1,M) cout << X[i] << " " << Y[i] << "\n" ; }
	
	Corner[1] = MP(1,1); 
	Corner[2] = MP(1,N);
	Corner[3] = MP(N,1); 
	Corner[4] = MP(N,N+N-1); 
	Corner[5] = MP(N+N-1,N); 
	Corner[6] = MP(N+N-1,N+N-1); 
	fo(i,1,N*2) fo(j,1,N*2) Bound[i][j] = false ;
	fo(i,1,N) Bound[1][i] = Bound[i][1] = Bound[i][N+i-1] =
	          Bound[N+i-1][i] = Bound[N+N-1][N+i-1] = Bound[N+i-1][N+N-1] = true ;
	fo(i,1,N*2-1) Bound[1][i] = Bound[N*2-1][i] = Bound[i][1] = Bound[i][N*2-1] = true ;
}

void Dfs( int x , int y ) {
	if ( x < 1 || x >= N+N || y < 1 || y >= N+N ) return ;
	if ( vis[x][y] ) return ;
	if ( !A[x][y] ) {
		vis[x][y] = true ;
		Dfs(x,y+1); Dfs(x+1,y); Dfs(x+1,y+1);
		Dfs(x,y-1); Dfs(x-1,y); Dfs(x-1,y-1);
	}
}

void Dfs_( int x , int y ) {
	if ( x < 1 || x >= N+N || y < 1 || y >= N+N ) return ;
	if ( vis[x][y] ) return ;
	if ( A[x][y] ) {
		vis[x][y] = true ; vis_[x][y] = true ;
		Dfs_(x,y+1); Dfs_(x+1,y); Dfs_(x+1,y+1);
		Dfs_(x,y-1); Dfs_(x-1,y); Dfs_(x-1,y-1);
	}
}

string Check() {
	bool p1 = false , p2 = false , p3 = false ;
	
	fo(i,1,N*2-1) fo(j,1,N*2-1) vis[i][j] = false ;
	fo(i,1,N*2-1) fo(j,1,N*2-1) if ( Bound[i][j] ) Dfs(i,j) ;
	
	// cout << "\n" ;
	// fo(i,1,N*2-1) { fo(j,1,N*2-1) cout << vis[i][j] ; cout << "\n" ; }
	
	fo(i,1,N*2-1) fo(j,1,N*2-1) if ( !vis[i][j] && !A[i][j] ) p1 = true ;
	
	fo(i,1,N*2-1) fo(j,1,N*2-1) vis_[i][j] = false ;
	fo(i,1,N*2-1) fo(j,1,N*2-1) if ( A[i][j] && !vis_[i][j] ) {
		fo(ii,1,N*2-1) fo(jj,1,N*2-1) vis[ii][jj] = false ;
		Dfs_(i,j) ;
		
		// cout << "\n" ;
		// fo(ii,1,N*2-1) { fo(jj,1,N*2-1) cout << vis[ii][jj] ; cout << "\n" ; }
		
		int cnt_cor = 0;
		int cnt_side = 0 ;
		fo(k,1,6) if ( vis[Corner[k].first][Corner[k].second] ) cnt_cor ++ ;
		
		bool pan ;
		
		
		
		pan = false ; fo(k,2,N-1) if ( vis[1][k] ) pan = true ; if ( pan ) cnt_side ++ ;
		pan = false ; fo(k,2,N-1) if ( vis[k][1] ) pan = true ; if ( pan ) cnt_side ++ ;
		pan = false ; fo(k,2,N-1) if ( vis[k][N+k-1] ) pan = true ; if ( pan ) cnt_side ++ ;
		pan = false ; fo(k,2,N-1) if ( vis[N+k-1][k] ) pan = true ; if ( pan ) cnt_side ++ ;
		pan = false ; fo(k,2,N-1) if ( vis[N+N-1][N+k-1] ) pan = true ; if ( pan ) cnt_side ++ ;
		pan = false ; fo(k,2,N-1) if ( vis[N+k-1][N+N-1] ) pan = true ; if ( pan ) cnt_side ++ ;
		
		// cout << "cnt_side=" << cnt_side << "\n" ;
		
		if ( cnt_cor >= 2 ) p2 = true ;
		if ( cnt_side >= 3 ) p3 = true ;
	}
	
	if ( !p1 && !p2 && !p3 ) return "none" ;
	if ( p1 && !p2 && !p3 ) return "ring in move" ;
	if ( !p1 && p2 && !p3 ) return "bridge in move" ;
	if ( !p1 && !p2 && p3 ) return "fork in move" ;
	if ( p1 && p2 && !p3 ) return "bridge-ring in move" ;
	if ( p1 && !p2 && p3 ) return "fork-ring in move" ;
	if ( !p1 && p2 && p3 ) return "bridge-fork in move" ;
	if ( p1 && p2 && p3 ) return "bridge-fork-ring in move" ;
}

void Solve() {
	fo(i,1,N*2-1) fo(j,1,N*2-1) A[i][j] = false ;
	string ret;
	fo(i,1,M) {
		A[X[i]][Y[i]] = true ;
		ret = Check() ;
		if ( ret != "none" ) { cout << ret << " " << i << "\n" ; return ; }
	}
	cout << "none\n" ;
}

int main() {
	freopen( "B.in" , "r" , stdin ) ; freopen( "B.out" , "w" , stdout ) ;
	int Test ; cin >> Test ;
	fo(i,1,Test) {
		Init() ;
		cout << "Case #" << i << ": " ;
		Solve() ;
	}
}