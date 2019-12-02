#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <set>
using namespace std;


int main() {
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int t;
	cin>>t;
	int cas = 1;
	while (t--) {
		
		int r, c, m;
		cin>>r>>c>>m;
		
		char a[55][55];
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) a[i][j] = '.';
		}
		
		if (r==1) {
			for (int i=0; i<m; i++) a[0][i] = '*';
			a[0][c-1] = 'c';
			m = 0;
		}
		else if (c==1) {
			for (int i=0; i<m; i++) a[i][0] = '*';
			a[r-1][0] = 'c';
			m = 0;
		}
		else {
			if (m==0) a[0][0] = 'c';
			for (int i=0; i<r-2; i++) {
				for (int j=0; j<c; j++) {
					if (m>0) {
						a[i][j] = '*';
						m--;
						if (m==0) {
							a[i+2][j] = 'c';
						}
					}
				}
			}
			if (m>0) {
				for (int j=0; j<c-2; j++) {
					if (m>1) {
						a[r-2][j] = '*';
						a[r-1][j] = '*';
						m -= 2;
						if (m==0) {
							a[r-1][j+2] = 'c';
						}
						else if (m==1) {
							a[r-2][j] = '*';
							a[r-1][j+2] = 'c';
							m -= 1;
						}
					}
					else if (m==1) {
						a[r-2][j] = '*';
						a[r-1][j+2] = 'c';
						m -= 1;
					}
				}
				if (m==3) {
					a[r-2][c-2] = '*';
					a[r-1][c-2] = '*';
					a[r-2][c-1] = '*';
					a[r-1][c-1] = 'c';
					m = 0;
				}
			}
		}
		if (m>0) printf("Case #%d:\nImpossible\n", cas);
		else {
			printf("Case #%d:\n", cas);
			for (int i=0; i<r; i++) {
				for (int j=0; j<c; j++) cout<<a[i][j];
				cout<<endl;
			}
		}
		cas++;
	}
 	
	return 0;
}

