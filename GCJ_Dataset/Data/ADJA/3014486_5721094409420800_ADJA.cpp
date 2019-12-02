#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

const int MAXN = 1050;

int tn;
int n;
int a[MAXN];
int l, r;

int main() {
	//assert(freopen("input.txt","r",stdin));
	//assert(freopen("output.txt","w",stdout));
    
    scanf("%d", &tn);

    for (int test = 1; test <= tn; test++) {
    	scanf("%d", &n);
    	for (int i = 1; i <= n; i++) {
    		scanf("%d", &a[i]);
    	}

    	int ans = 0;

    	l = 1, r = n;
    	for (int i = 1; i <= n; i++) {

    		int mn = a[l], mp = l; 
    		for (int j = l; j <= r; j++) {
    			if (a[j] < mn) {
    				mn = a[j];
    				mp = j;
				}
    		}

    		/*for (int i = 1; i <= n; i++)
    			printf("%d ", a[i]);

    		printf("DD %d %d\n", mn, mp);  */


    		if (mp - l < r - mp) {
    			for (int i = mp; i > l; i--) {
    				swap(a[i], a[i - 1]);
    				ans++;
				}
				l++;
    		}
    		else {
    			for (int i = mp; i < r; i++) {
    				swap(a[i], a[i + 1]);
    				ans++;
				}
				r--;
    		}

    	}

   		printf("Case #%d: %d\n", test, ans);

    }

	return 0;
}