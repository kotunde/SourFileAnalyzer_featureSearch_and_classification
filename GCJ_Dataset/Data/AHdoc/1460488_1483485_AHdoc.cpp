const char a[26] = {
	'y' ,  // a
	'h' ,  // b
	'e' ,  // c
	's' ,  // d
	'o' ,  // e
	'c' ,  // f
	'v' ,  // g
	'x' ,  // h
	'd' ,  // i
	'u' ,  // j
	'i' ,  // k
	'g' ,  // l
	'l' ,  // m
	'b' ,  // n
	'k' ,  // o
	'r' ,  // p
	'z' ,  // q
	't' ,  // r
	'n' ,  // s
	'w' ,  // t
	'j' ,  // u
	'p' ,  // v
	'f' ,  // w
	'm' ,  // x
	'a' ,  // y
	'q'    // z
	};

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

const int MaxN = 509 ;

int N ;
char s[MaxN] ;
char t[MaxN] ;

void Init() {
	fo(i,0,254) t[i] = i ;
	fo(i,0,25 ) t['a'+i] = a[i] ;
}

void Solve() {
	cin >> N ; gets(s) ;
	fo(cases,1,N) {
		gets(s); int len = strlen(s) ;
		fo(i,0,len-1) s[i] = t[s[i]] ;
		cout << "Case #" << cases << ": " << s << "\n" ;
	}
}

int main() {
	freopen("A.in" ,"r" , stdin) ;
	freopen("A.out","w" , stdout) ;
	Init() ;
	Solve() ;
}