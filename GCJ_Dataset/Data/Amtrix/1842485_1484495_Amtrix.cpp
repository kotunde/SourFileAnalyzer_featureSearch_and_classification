#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string.h>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <assert.h>
#include <math.h>
#include <time.h>
#include <fstream>
#include <sstream>
using namespace std;

#define f first
#define s second
#define mk make_pair
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const int maxn = 1000 + 55;

struct rect{
    int r,c;
    int w,h;
    rect(){};
    rect(int p1, int p2, int p3, int p4) {
        r = p1, c = p2, h = p3, w = p4;
    }

    const bool operator<(const rect &r) const {
        return h*w < r.h*r.w;
    }
};

int n,h,w;
int r[maxn];
int dx[maxn];

int szc(int x, int y) {
    return r[x] > r[y];
}

const double eps = 1e-9;

double solx[maxn];
double soly[maxn];

int main() {
    freopen("Ulaz.txt","r",stdin);
    freopen("Izlaz.txt","w",stdout);
    int tests; scanf("%d",&tests);
    for (int t = 1; t <= tests; ++t) {
        scanf("%d%d%d",&n,&w,&h);

        for (int i = 0; i < n; ++i) {
            scanf("%d",&r[i]);
            dx[i] = i;
        }


        priority_queue< rect > pq;
        pq.push( rect(0, 0, h, w));

        sort(dx, dx + n, szc);
        for (int i = 0; i < n; ++i) {
            int x = dx[i];
            rect inside;
            double add_r, add_c;
            do{
                inside = pq.top(); pq.pop();
                add_r = r[x] * (inside.r != 0);
                add_c = r[x] * (inside.c != 0);
                solx[x] = inside.c + add_c;
                soly[x] = inside.r + add_r;
            } while( solx[x]-eps > w || soly[x]-eps > h);

            pq.push(rect(inside.r + r[x] + add_r, inside.c, inside.h - r[x] - add_r, inside.w));
            if(inside.r == 0)
                pq.push(rect(inside.r, inside.c + r[x] + add_c, inside.h, inside.w - r[x] - add_c));

        }


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if( i == j) continue;
                double dst = (solx[i] - solx[j])*(solx[i] - solx[j]);
                dst += (soly[i] - soly[j])*(soly[i] - soly[j]);
                dst = sqrt(dst);
                double dstr = r[i] + r[j];
                if(dst+ eps < dstr) {
                    printf("WA: %d %d %.10lf %.10lf\n",i,j,dst, dstr);
                    while(1);
                }
            }
        }


        printf("Case #%d: ", t);
        for (int i = 0; i < n; ++i) {
            if(solx[i]-eps > w || soly[i]-eps > h) {
                cout<<"WA on: "<<i<<endl;
                while(1);
            }
            printf("%.1lf %.1lf ",solx[i], soly[i]);
        }
        printf("\n");

    }
    return 0;
}
