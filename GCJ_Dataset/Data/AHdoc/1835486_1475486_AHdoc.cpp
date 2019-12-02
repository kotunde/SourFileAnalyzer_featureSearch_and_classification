#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int N ;
struct TT{ int l , p , num ; } A[1009] ;
bool Compare(TT im_1,TT im_2) { return ( im_1.l * im_2.p == im_1.p * im_2.l ) ? ( im_1.num < im_2.num ) : ( im_1.l * im_2.p < im_1.p * im_2.l ) ; }
void Solve( int Test ) {
	cin >> N ;
	fo(i,1,N) cin >> A[i].l ;
	fo(i,1,N) cin >> A[i].p ;
	fo(i,1,N) A[i].num = i-1 ;
	sort(A+1 , A+N+1 , Compare) ;
	cout << "Case #" << Test << ":" ;
	fo(i,1,N) cout << " " << A[i].num ;
	cout << "\n" ;
}
int main() {
	// freopen( "A.in" , "r" , stdin ) ; freopen( "A.out", "w" , stdout) ;
	freopen( "A-small.in" , "r" , stdin ) ; freopen( "A-small.out", "w" , stdout) ;
	// freopen( "A-large.in" , "r" , stdin ) ; freopen( "A-large.out", "w" , stdout) ;
	int Test ; cin >> Test ;
	fo(i,1,Test) Solve(i) ;
}