#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;

#define SMALL 1
//#define LARGE 1

char arr[100][100];

int main() {
#ifdef LARGE
	freopen("c_large.i", "rt", stdin);
	freopen("c_large.o", "wt", stdout);
#elif SMALL
	freopen("c_small_3.i", "rt", stdin);
	freopen("c_small_3.o", "wt", stdout);
#else
	freopen("c_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		int r,c,m;
		cin>>r>>c>>m;
		bool transpose = false;
		if(r < c) {
			swap(r,c);
			transpose = true;
		}
		cout << "Case #" << tt << ":" << endl;
		if( m == r*c || ((r>1 && c>1 && m >= r*c-c-1) && (m!=(r*c-1)) && m != 0)) {
			cout << "Impossible" << endl;
			continue;
		}
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++) {
				if(i*c+j+1 <= m)
					arr[i][j] = '*';
				else
					arr[i][j] = '.';
			}
		arr[r-1][c-1] = 'c';
		if(transpose) {
			for(int i=0;i<c;i++) {
				for(int j=0;j<r;j++)
					cout << arr[j][i];
				cout<<endl;
			}
		} else {
			for(int i=0;i<r;i++) {
				for(int j=0;j<c;j++)
					cout << arr[i][j];
				cout<<endl;
			}
		}
	}

	return 0;
}
