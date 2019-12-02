#pragma comment(linker, "/STACK:10000000")
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric> 
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> T inline sqr(T x) { return x * x; }
template <class T> string str( T i ) { stringstream ss; ss << i; return ss.str(); }
int toint(string a) {istringstream is(a); int p; is>>p; return p;} 
long long toll(string a){istringstream is(a);long long p;is>>p;return p;} 

#define pb push_back
#define mp make_pair
#define e1 first 
#define e2 second 
#define sz size 

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif
#define forn(i, n) for (i = 0; i < int(n); i++)
#define setval(a,v) memset(a, v, sizeof(a))
const ld pi = 3.1415926535897932384626433832795, eps = 1e-8;

char a[500];

int main()
{
//   freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   string w = "yhesocvxduiglbkrztnwjpfmaq";
	//cerr << w.sz() << endl;
	//cerr << w.sz() << endl;
	string s[100];
	int n;
	cin >> n;
	getline(cin, s[0]);
	int i, j;
	forn (i, n)
		getline(cin, s[i]);
	forn (i, n)
	{
		cout << "Case #" << i + 1 << ": ";
		forn (j, s[i].sz())
		{
			//if (i == 6)
				//cerr << j;
			if (s[i][j] == ' ')
			{
				cout << " ";
				continue;
			}
			if (s[i][j] > 'z')
			{
				cout << char(w[s[i][j] - 'A'] - 'a' + 'A');
			}
			else
				cout << char(w[s[i][j] - 'a']);
		}
		cout << endl;
	}
	return 0;
}

