/*****************************************
*
* @ingroup UESTC_ACM,2012
* @param   C
* @author  a180285
*
*****************************************/

# include <assert.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <algorithm>
# include <iostream>
# include <string>
# include <queue>
# include <stack>
# include <map>
# include <set>
# include <vector>
# include <cstring>
# include <list>
# include <ctime>
# include <sstream>

# pragma comment (linker,"/STACK:16777216")

# define For(i,a)   for(i=0; i<(a); i++)
# define sz(a)      (sizeof(a))
# define MEM(a)     (memset((a),0,sizeof(a)))
# define MEME(a)    (memset((a),-1,sizeof(a)))
# define MEMX(a)    (memset((a),0xf,sizeof(a)))
# define pb(a)      push_back(a)

using namespace std;

typedef long long           ll      ;
typedef unsigned long long  ull     ;
typedef unsigned int        uint    ;
typedef unsigned char       uchar   ;
typedef istringstream        Iss     ;

template<class T> inline const T& MIN(const T& a,const T& b){return a<b? a : b;}
template<class T> inline const T& MAX(const T& a,const T& b){return a>b? a : b;}
template<class T> inline void checkmin(T &a,const T& b){if(a>b) a=b;}
template<class T> inline void checkmax(T &a,const T& b){if(a<b) a=b;}

const ll oo=(1ll<<63) - 1          ;
const double eps=1e-7       ;
const int N=256               ;
const int M=1               ;
const ll P=10000000097ll    ;

struct dot
{
    ll p, t;
};

dot d[N];
int n;
ll money, fee;

int cmp(dot a,dot b)
{
    if( a.t != b.t )
        return a.p < b.p;
    return a.t > b.t;
}

ll xx(ll a,ll b)
{
    if( 0 == a )
        return 0;
    if( oo/a < b )
        return oo;
    return a * b;
}

ll add(ll a,ll b)
{
    if( oo - a < b )
        return oo;
    return a + b;
}

void def(ll &p,ll &t)
{
    p = fee;
    t = d[0].t;
    int i,j,k;
    ll out = fee;
    ll pic = d[0].p;
    for(i=1; i<n; i++)
    {
        if( oo == p )
            break;
        ll dt = d[i].t - t;
        ll dp = d[i].p - pic;
        if( xx(dp, dt) <= out )
        {
            p += xx(dp, dt);
            t += dt;
            out -= xx(dp, dt);
        }
        else
        {
            dt = out / pic;
            p += xx(dp, dt);
            t += dt;
            out -= xx(dp, dt);
            break;
        }
    }
    p = add(p, xx(t, pic));
    //printf("%lld %lld\n", p, t);
}

ll other()
{
    ll ans = 0;
    int i;
    if( money <= fee )
        return 0;
    money -= fee;
    For(i, n)
    {
        //printf("p i p -> %lld\n", d[i].p);
        ll dt = d[i].t - ans;
        if( xx(dt, d[i].p) <= money )
        {
            money -= dt * d[i].p;
            ans += dt;
        }
        else
        {
            //printf("p i p -> %lld\n", d[i].p);
            dt = money / d[i].p;
            money -= dt * d[i].p;
            ans += dt;
            break;
        }
    }
    //printf("other -> %lld\n", ans);
    return ans;
}

ll doit()
{
    scanf("%lld %lld %d", &money, &fee, &n);
    int i,j,k;
    For(i, n)
    {
        scanf("%lld %lld", &d[i].p, &d[i].t);
        d[i].t++;
    }
    sort(d, d+n, cmp);
    ll p, t;
    def(p, t);
    ll ans = 0;
    ans = (money / p) * t;
    money -= (ans/t) * p;
    //printf("in other\n");
    //printf("n -> %d\n", n);
    ans += other();
    return ans;
}

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int T,_=0;
    scanf("%d",&T);
    while( _++ < T )
    {
        ll ans = doit();
        printf("Case #%d: %lld\n", _, ans);
    }
    return 0;
}

/**

Input

Output

3
32 5 2
5 0
10 2
10 10 1
10 10
10 1 1
1 5
Case #1: 3
Case #2: 0
Case #3: 8
**/

