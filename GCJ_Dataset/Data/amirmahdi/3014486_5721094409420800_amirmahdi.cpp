#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>

#define rep(i,n) for(int i=0;i<n;i++)
#define VI vector<int>
#define pb(x) push_back(x)
#define ll long long
#define For(i,a,b) for(int i=a;i<b;i++)
#define sz(s) int(s.size())
using namespace std;
const int maxn = 100100;

int a[maxn];
int b[maxn];

long long mergesort(int s, int f){
	if(f-s <= 1)
		return 0;
	int m = (s+f)/2;
	long long res = 0;
	res+= mergesort(s, m);
	res+= mergesort(m, f);

	int  i1 = s, i2 = m;
	int top = 0;
	while(i1 < m || i2 < f){
		if(i1 < m){
			if(i2 < f && a[i2] < a[i1]){
				b[top++] = a[i2];
				res+= m - i1;
				i2++;
			}else{
				b[top++] = a[i1];
				i1++;
			}
		}else{
			b[top++] = a[i2];
			i2++;
		}
	}
//	cout << s << " " << f << " " << top << " "  << res << endl;
	rep(i,top)
		a[s+i] = b[i];
	return res;
}
int c[maxn];

bool bit(int x, int y){
	return (x >> y)&1;
}

int main() {
	int t;
	cin >> t;
	rep(g,t){
		int n;
		cin >> n;
		int maxid = 0;
		rep(i,n){
			cin >> c[i];
			if(c[i] > c[maxid])
				maxid = i;
		}
		int ans = n*n;
		rep(i, (1<<n)){
			VI x,y;
			int tmp = 0;
			rep(j,n)
				if(bit(i, j)){
					y.pb(c[j]);
					For(k,j+1,n)
						if(!bit(i, k))
							tmp++;
				}else
					x.pb(c[j]);
			copy(x.begin(), x.end(), a);
			tmp+= mergesort(0, x.size());
			copy(y.rbegin(), y.rend(), a);
			tmp += mergesort(0, y.size());
			if(tmp < ans)
				ans = tmp;
		}
	/*	for(int i=maxid;i>0;i--)
			swap(c[i], c[i-1]);
		rep(i, n){
			VI x,y;
			int tmp = 0;
			tmp += abs(maxid-i);
			for(int j=0;j<i;j++)
				x.pb(c[j]);
			For(j,i+1,n)
				y.pb(c[j]);

			copy(x.begin(), x.end(), a);
			tmp+= mergesort(0, x.size());
			copy(y.rbegin(), y.rend(), a);
			tmp += mergesort(0, y.size());
			//cout << c[i] << " " << tmp << endl;
			if(tmp < ans)
				ans = tmp;
			swap(c[i], c[i+1]);
		}*/
		cout << "Case #" << g+1 << ": " << ans << endl;
	}
	return 0;
}
