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

int t;
int ar, br;
int a[10][10], b[10][10];
set <int> st;
int ans = -1;
bool many = false;

int main() {
	//assert(freopen("input.txt","r",stdin));
	//assert(freopen("output.txt","w",stdout));

	scanf("%d", &t);
	for (int test = 1; test <= t; test++) {
		scanf("%d", &ar);
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
				scanf("%d", &a[i][j]);	

		scanf("%d", &br);
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
				scanf("%d", &b[i][j]);

		st.clear();
	    for (int j = 1; j <= 4; j++)
	    	st.insert(a[ar][j]);

	    many = false; ans = -1;
	    for (int j = 1; j <= 4; j++) {
	    	int cur = b[br][j];
	    	if (st.count(cur) > 0) {
	    		if (ans == -1)
	    			ans = cur;
	    		else
	    			many = true;
	    	}
	    } 

	    printf("Case #%d: ", test);

	    if (ans == -1) 
	    	puts("Volunteer cheated!");
	    else if (many) 
	    	puts("Bad magician!");
	    else
	    	printf("%d\n", ans);
	}

	return 0;
}