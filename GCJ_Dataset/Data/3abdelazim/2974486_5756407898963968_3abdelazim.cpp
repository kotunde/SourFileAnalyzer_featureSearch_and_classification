#include <cstdio>
#include <vector>

using namespace std;

#define For(i,a,b) for(int i = a; i < b; i++)

int nextInt() {
	int x;
	scanf("%d", &x);
	return x;
}


int main() {
	freopen("out.txt", "w", stdout);
	int tt = nextInt(); 
	For(t,1,tt+1) {
		vector <int> v(16);
		For(x,0,2) {
			int r = nextInt() - 1;
			int m[4][4];
			For(i,0,4)
			For(j,0,4)
				m[i][j] = nextInt() - 1;
			For(i,0,4)
				v[m[r][i]]++;
		}
		int res = -1;
		int state = 0;
		For(i,0,16) {
			if (v[i] > 1) {
				res = i + 1;
				state++;
			}
		}
		printf("Case #%d: ", t);
		if (state == 0) {
			printf("Volunteer cheated!\n");
		}
		else if (state == 1) {
			printf("%d\n", res);
		}
		else {
			printf("Bad magician!\n");
		}
	}
}

