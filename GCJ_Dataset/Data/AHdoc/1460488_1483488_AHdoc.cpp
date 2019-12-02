#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <cmath>
using namespace std ;

#define MP make_pair
#define PB push_back

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fi(i,a,b) for(int i=a;i>=b;i--)

int L , R ;
set< pair<int , int> > Ans ;

void Check( int num ) {
	int ten = 1 , r = 0 ;
	while ( ten <= num ) ten *= 10 , r ++ ;
	ten /= 10 ;
	int x = num ;
	fo(i,1,r-1) {
		if ( x%10 != 0 && (int)(x/10) + (x%10)*ten > num && (int)(x/10) + (x%10)*ten <= R )
			Ans.insert( MP(num , (int)(x/10) + (x%10)*ten ) ) ;
		x = (int)(x/10) + (x%10)*ten ;
	}
}

int main() {
	freopen( "C.in" , "r" , stdin ) ;
	freopen( "C.out", "w" , stdout) ;
	
	int Test ; cin >> Test ;
	fo(i,1,Test) {
		cin >> L >> R ;
		cout << "Case #" << i << ": " ;
		Ans.clear() ;
		fo(x,L,R) Check(x) ;
		cout << Ans.size() << "\n" ;
	}
}