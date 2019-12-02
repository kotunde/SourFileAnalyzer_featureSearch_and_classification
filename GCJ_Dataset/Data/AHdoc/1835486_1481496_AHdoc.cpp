#include <iostream>
#include <cstdio>
#include <cstring>
#define MP make_pair
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fi(i,a,b) for(int j=a;j>=b;j--)
#define MEM(a) memset(a,0,sizeof(a))
using namespace std ;

const int MaxN = 5009 ;

int N , K , Ans ;
bool A[509][509] ;
int Input_Degree[509] , Output_Degree[509] ;
char ss[MaxN] ;

const string constr = "oieastbg" ;

void Create(char ch, int a[], int &len) {
	a[len=1] = ch ;
	fo(i,0,7) if ( ch == constr[i] ) a[++len] = (char)(i+'0') ;
}

void Init() {
	scanf("%d", &K) ; scanf("%s", ss) ; N = strlen(ss) ;
	MEM(A) ;
	Ans = 0;
	int a1[10], a2[10], l1, l2;
	fo(i,1,N-1) {
		Create(ss[i - 1], a1, l1) ; Create(ss[i], a2, l2) ;
		fo(i1,1,l1) fo(i2,1,l2) if ( !A[a1[i1]][a2[i2]] ) { A[a1[i1]][a2[i2]] = true ; Ans ++ ; }
	}
}

void Solve() {
	MEM(Input_Degree) ; MEM(Output_Degree) ;
	fo(i,1,300) fo(j,1,300) if ( A[i][j] ) Output_Degree[i] ++ , Input_Degree[j] ++ ;
	int t = 0 ;
	fo(i,1,300) if ( Input_Degree[i] < Output_Degree[i] ) t += Output_Degree[i] - Input_Degree[i] ;
	if ( t == 0 ) cout << Ans+1 << "\n" ;
	else cout << Ans+t << "\n" ;
}

int main() {
	freopen( "D.in" , "r" , stdin ) ; freopen( "D.out", "w" , stdout) ;
	int Test ; cin >> Test ;
	fo(i,1,Test) {
		cout << "Case #" << i << ": " ;
		Init() ; Solve() ; 
	}
}


