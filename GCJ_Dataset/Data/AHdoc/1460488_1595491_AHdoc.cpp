#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
using namespace std ;

#define MP make_pair
#define PB push_back

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fi(i,a,b) for(int i=a;i>=b;i--)

const int MaxN = 1019 ;

int N , S , T ;
int t1[MaxN] , t2[MaxN] , A[MaxN] , F[MaxN][MaxN];

#define max(a,b) (((a) > (b) ? (a) : (b)))
#define MEM(a) memset((a) , 0xff , sizeof((a)))

void Init() {
	MEM(t1) ; MEM(t2) ;
	fo(i,0,10) t2[i*3] = i ;
	fo(i,0,9) {
		t2[i*3+1] = max(t2[i*3+1] , i+1) ;
		t2[i*3+2] = max(t2[i*3+1] , i+1) ;
	}
	fo(i,0,8) {
		t1[i*3+2] = max(t1[i*3+2] , i+2) ;
		t1[i*3+3] = max(t1[i*3+3] , i+2) ;
		t1[i*3+4] = max(t1[i*3+4] , i+2) ;
	}
}

void Solve() {
	cin >> N >> S >> T ;
	fo(i,1,N) cin >> A[i];
	MEM(F) ; F[0][0] = 0 ;
	fo(i,0,N-1) fo(j,0,S) if ( F[i][j] >= 0 ) {
		if ( t1[A[i+1]] >= T ) F[i+1][j+1] = max( F[i+1][j+1] , F[i][j]+1 ) ;
		else                   F[i+1][j+1] = max( F[i+1][j+1] , F[i][j]   ) ;
		
		if ( t2[A[i+1]] >= T ) F[i+1][j] = max( F[i+1][j] , F[i][j]+1 ) ;
		else                   F[i+1][j] = max( F[i+1][j] , F[i][j]   ) ;
	}
	cout << F[N][S] << "\n" ;
}

int main() {
	freopen( "B.in" , "r" , stdin ) ;
	freopen( "B.out", "w" , stdout) ;
	
	Init() ;
	int Test ; cin >> Test ;
	fo(i,1,Test) {
		cout << "Case #" << i << ": " ;
		Solve() ;
	}
}