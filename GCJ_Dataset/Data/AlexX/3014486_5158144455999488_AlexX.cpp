#include<iostream>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<sstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<numeric>
#include<utility>
#include<cstdlib>
#include<cstring>
#include<ctime>

using namespace std;

const int INF = 0X3F3F3F3F;
const double PI = acos(-1.0); //3.1415926535897932384626433832795;
const double EPS = 1e-11;
const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
const int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1}; //4 direction

#define FOR(i,s,e) for(int i=(s);i<=(int)(e);++i)
#define FORD(i,s,e) for(int i=(s);i>=(int)(e);--i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REPD(i,n) for(int i=(n)-1;i>=0;--i)
#define CLR(x) memset((x),0,sizeof(x));
#define MEM(a,b) memset((a),b,sizeof(a));
#define PRV(v) REP(vi,v.size()) cout << v[vi] << ' ';cout << endl

inline int sgn(double x) { return x < -EPS ? -1 : x > EPS ? 1 : 0; }
//inline string tolower(string s){ REP(i,s.SZ) s[i] = tolower(s[i]); return s; }
//inline string toupper(string s){ REP(i,s.SZ) s[i] = toupper(s[i]); return s; }

template<class T> inline T sqr(const T& x) { return x * x; }
template<class T> inline int toint(const T& x){ stringstream ss; ss << x; int r; ss >> r; return r; } 
template<class T> inline int todouble(const T& x){ stringstream ss; ss << x; double r; ss >> r; return r; } 
template<class T> inline string tostr(const T& x) { ostringstream os(""); os << x; return os.str(); }
template<class T> void stov(string s,vector<T> &vi){vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));}//NOTES:stov(
template<class T> void vtos(vector<T> vi,string &s){ostringstream sout;for (int i=0;i<vi.size();i++){if(i>0)sout<<' ';sout<<vi[i];}s=sout.str();}

typedef long long LL;
typedef double DB;
typedef stringstream SS;
typedef set< int > SI;
typedef pair< int, int > PII;
typedef vector< int > VI;
typedef vector< VI > VVI;
typedef vector< string > VS;
typedef map< string, int > MSI;
typedef map< int, int > MII;

const int MAXN = 10010;

int dir[4][2] = {0, 1, -1, 0, 0, -1, 1, 0};
int board[512][512];
int w, h, n, ans, clk;

bool dfs(int x, int y, int d){    
    if (board[x][y] != 0) return false;
    if (y == h - 1) {
        board[x][y] = clk;
        return true;   
    }
    for(int k = d + 1 + 4; k >= d - 1 + 4; --k) {
        int nx = x + dir[k%4][0], ny = y + dir[k%4][1];
        if (x < 0 || y < 0 || x >= w || y >= h) continue;           
        board[x][y] = -1;
        if (dfs(nx, ny, k%4)) {
            board[x][y] = clk;
            return true;   
        }
    }
    return false;    
}

int x0, x1, z0, z1;

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    //freopen("C-small-1.in", "r", stdin);
    //freopen("cs.in", "r", stdin);
    //freopen("C-small-1.out", "w", stdout);
    freopen("c-small.out", "w", stdout);
    //freopen("A-large-practice.out", "w", stdout);
    int cas;
    scanf("%d", &cas);    
    REP(T, cas) {
        cin>>w>>h>>n;
        memset(board, 0, sizeof(board));
        REP(i, n) {
            cin>>x0>>z0>>x1>>z1;
            FOR(i, x0, x1)
            FOR(j, z0, z1) board[i][j] = -1;
        }
        ans = 0, clk = 0;
        REP(i, w) {
            ++clk;
            ans += dfs(i, 0, 0);
            //cout<<'ans= '<<ans<<endl;
        }
        cout<<"Case #"<<T+1<<": "<<ans<<endl;
    }
    return 0;
}
