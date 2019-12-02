/*****************************************
*
* @ingroup UESTC_ACM,2012
* @param   A
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

const int oo=1<<30          ;
const double eps=1e-7       ;
const int N=128               ;
const int M=1               ;
const ll P=10000000097ll    ;

int t[N], p[N];
int n;
int d[N];

int cmp(int a,int b)
{
    if( t[a]*p[a] != t[b]*p[b] )
        return t[a]*p[a] > t[b]*p[b];
    return a < b;
}

void doit()
{
    int i, j, x;
    scanf("%d", &n);
    For(i, n)
    {
        scanf("%d", &t[i]);
    }
    For(i, n)
    {
        scanf("%d", &p[i]);
        d[i] = i;
    }
    sort(d, d+n, cmp);
    For(i, n)
    {
        printf(" %d", d[i]);
    }
}

int main()
{
    int T,_=0;
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d",&T);
    while( _++ < T )
    {
        printf("Case #%d:", _);
        doit();
        puts("");
    }
    return 0;
}

/**

Input

Output

3
4
1 1 1 1
50 0 20 20
3
100 10 1
0 50 0
3
100 80 50
40 20 80
Case #1: 0 2 3 1
Case #2: 1 0 2
Case #3: 2 0 1


**/
