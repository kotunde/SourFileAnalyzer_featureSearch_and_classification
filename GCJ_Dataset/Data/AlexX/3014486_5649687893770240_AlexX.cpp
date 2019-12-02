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

const int MAXM = 30;
int n, m, num;
char s[MAXM], str[10][MAXM];

struct node{
    node* next[26];
    void init() {memset(next, 0, sizeof(next));}
} a[262144], *root[4];

void insert(node *root, char *s) {
    node *p = root;
    for(int i = 0; s[i]; ++i) {
        int x = s[i] - 'A';        
        if (p->next[x] == NULL) {
            a[num].init();
            p->next[x] = &a[num++];
        }
        p = p->next[x];
    }
}

int id[MAXM], visited[64], nodeMax = -1, wayMax = 0;

void dfs(int now, int m, int n) {
    if (now == m) {
        REP(i, n) if (visited[i] == 0) return;
        int numNode = 0;
        num = 0;
        REP(i, n) {
            root[i] = &a[num++];
            root[i]->init();
        }
        REP(i, m)  insert(root[id[i]], str[i]);
        numNode = num;
        if (numNode > nodeMax) 
            nodeMax = numNode, wayMax = 1;
        else if (numNode == nodeMax) 
            wayMax++;
        return;
    }
    REP(i, n) {
        visited[i]++, id[now] = i;        
        dfs(now + 1, m, n);
        visited[i]--;
    }
}

int main() {
    freopen("D-small-attempt0.in", "r", stdin);
    //freopen("C-large.in", "r", stdin);
    freopen("D-small.out", "w", stdout);
    //freopen("A-large-practice.out", "w", stdout);
    int cas;
    scanf("%d", &cas);    
    REP(T, cas) {        
        scanf("%d %d", &m, &n);
        getchar();
        nodeMax = -1, wayMax = 0;        
        REP(i, m) gets(str[i]);
        memset(visited, 0, sizeof(visited));
        dfs(0, m, n);
        printf("Case #%d: %d %d\n", T+1, nodeMax, wayMax);        
    }
    return 0;
}
