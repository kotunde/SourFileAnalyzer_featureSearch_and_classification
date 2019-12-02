#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 110;

int n;
int a[MAXN];
int p,s;

int f[MAXN][MAXN];

int main(){
	int T; cin >> T;
	for(int t = 0; t < T; t++ ){
		cin >> n >> s >> p;
		for( int i = 0; i < n; i++ )
			cin >> a[i];

		memset(f,0,sizeof(f));
		f[0][0] = 0;
		
		for( int i = 0; i < n; i++ ){
			for( int x = 0; x+x+x <= a[i]; x++ )
				for( int y = x; x+y+y <= a[i] && y <= x + 2; y++ )
					for( int z = y; x+y+z <= a[i] && z <= x+2 ; z++ )
						if ( x + y + z == a[i] ){
							int sur = ( z - x ) == 2;
							int best = z;
							for( int j = 0; j <= i; j++ )
								f[i+1][j+sur] = max( f[i+1][j+sur], f[i][j] + ( best >= p ) );
						}
		}

		cout << "Case #" << (t+1) << ": " << f[n][s] << endl;
	}
	return 0;
}
