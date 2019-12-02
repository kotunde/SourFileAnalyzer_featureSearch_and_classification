#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
using namespace std;

int a[4][4];

int main() {
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int t;
	cin>>t;
	int cas = 1;
	while (t--) {
		int r;
		cin>>r;
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++) {
				cin>>a[i][j];
			}
		}
		map<int,int> cnt;
		for (int i=0; i<4; i++) cnt[a[r-1][i]]++;
		cin>>r;
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++) {
				cin>>a[i][j];
			}
		}
		int p = -1;
		for (int i=0; i<4; i++) cnt[a[r-1][i]]++;
		for (map<int,int>::iterator it=cnt.begin(); it!=cnt.end(); it++) {
			if ((*it).second==2) {
				if (p==-1) p = (*it).first;
				else p = -2;
			}
		}
		if (p==-1) printf("Case #%d: Volunteer cheated!\n", cas);
		else if (p==-2) printf("Case #%d: Bad magician!\n", cas);
		else printf("Case #%d: %d\n", cas, p);
		cas++;
	}
 	
	return 0;
}

