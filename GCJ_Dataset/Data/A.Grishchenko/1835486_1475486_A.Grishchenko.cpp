#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <sstream>
typedef long long ll;
using namespace std;

#define REPi(n) for(int i=0;i<n;++i)
#define REP(i,a,b) for(int i=a;i<=b;++i)

#define mp make_pair
#define pb push_back
#define all(a) a.begin(),a.end()

#define sz(x) int((x).size())

string inttostr (int a) {
    string s;
    ostringstream os;
    os << a;
    s = os.str();
    return s;
}

void solve( )
{
	int tc_num;
	cin>>tc_num;
	for (int test_case = 1; test_case <= tc_num; ++test_case) {
		int N;
		cin >> N;
		vector<int> used (N,0);
		vector<int> L (N, 0);
		vector<int> P (N, 0);
		for (int i = 0; i < N; ++i)
			cin >> L[i];
		for (int i = 0; i < N; ++i)
			cin >> P[i];

		vector<int> res;
		int Lsum = 0;
		for (int i = 0; i < N; ++i) {
			int max_w = -1;
			int max_j = 0;
			for (int j = 0; j < N; ++j)
				if (used[j] != 1) {
					int s = P[j]*(L[j] + Lsum);
					if (max_w < s) {
						max_w = s;
						max_j = j;
					}
				}
			used[max_j] = 1;
			Lsum += L[max_j];
			res.push_back(max_j);
		}

		cout<<"Case #" << test_case << ": ";
		for (int i = 0; i < N; ++i)
			cout << res[i] << " ";
		cout << endl;
	}
} 

void main()
{
    #ifdef _DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    solve();
}