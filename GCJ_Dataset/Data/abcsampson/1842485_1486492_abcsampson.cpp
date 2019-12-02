#include <cstdio>
#include <algorithm>
#include <vector>
#define LL long long
#define N 2005
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
using namespace std;

int t, n, h[N], l;
struct pt{
	LL y, x;
} p[N];

LL cross(pt o, pt a, pt b){
	return (a.y - o.y) * (b.x - o.x) - (a.x - o.x) * (b.y - o.y);
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-out.txt", "w", stdout);
	
	scanf("%d", &t);
	FI(z, 1, t){
		scanf("%d", &n);
		fi(i, 1, n) scanf("%d", &h[i]);
		FI(i, 1, n) p[i].x = i;
		l = 1 << 30;
		
		bool ok = 1;
		p[n].y = l >> 1;
		FD(i, n - 1, 1){
			int la = 0, lb, lc = l;
			while(la < lc){
				lb = la + lc >> 1;
		//		printf("pt %d l h %d %d %d\n", i, la, lb, lc);
				bool fg = 1;
				pt temp = {lb, i};
				
				fi(j, i + 1, h[i]) if(cross(temp, p[j], p[h[i]]) >= 0){
					fg = 0;
					break;
				}
				
				if(fg) lc = lb;
				else la = lb + 1;
			}
			
			int ha = 0, hb, hc = l;
			while(ha < hc){
		//		printf("pt %d hl hh %d %d\n", i, ha, hc);
				hb = ha + hc >> 1;
				
				bool fg = 1;
				pt temp = {lb, i};
				
				fi(j, h[i] + 1, n) if(cross(temp, p[h[i]], p[j]) < 0){
					fg = 0;
					break;
				}
				
				if(fg) ha = hb + 1;
				else hc = hb;
			}
			
			la++;
			if(la > hc){
				ok = 0;
				break;
			}
			
			p[i].y = la + hc >> 1;
		}
		
		printf("Case #%d:", z);
		if(!ok) puts(" Impossible");
		else{
			FI(i, 1, n) printf(" %d", p[i].y);
			puts("");
		}
	}
	
	scanf("\n");
}
