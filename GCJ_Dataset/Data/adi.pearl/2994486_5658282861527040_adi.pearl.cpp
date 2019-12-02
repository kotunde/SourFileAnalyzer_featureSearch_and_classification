/*
  Aditya Gourav
  @adi.pearl
*/
#include<bits/stdc++.h>
using namespace std;

//scanning
#define si(x) scanf("%d",&x)
#define ss(x) scanf("%s",x)
#define ssWSP(x) scanf(" %[^\r\n]",x)
#define sill(x) scanf("%lld",&x)
#define sd(x) scanf("%lf",&x)

//debugging
#define dbm1(msg,x) cerr<<(msg)<<" "<<(x)<<endl;
#define dbm2(msg,x,y) cerr<<(msg)<<" "<<(x)<<" "<<(y)<<endl;
#define dbm3(msg,x,y,z) cerr<<(msg)<<" "<<(x)<<" "<<(y)<<" "<<(z)<<endl;
#define dbm(msg) cerr<<(msg)<<endl;
#define db1(x) cerr<<(x)<<endl;
#define db2(x,y) cerr<<(x)<<" "<<(y)<<endl;
#define db3(x,y,z) cerr<<(x)<<" "<<(y)<<" "<<(z)<<endl;

//printing to console
#define pi(x) printf("%d\n",x)
#define pi2(x,y) printf("%d %d\n",x,y)
#define pill(x) printf("%lld\n",x)
#define pd(x) printf("%lf\n",x)
//others
#define ForInc(var,beg,end) for(int var=beg;var<=end;++var)
#define advForInc(var,beg,end,inc) for(int var=beg;var<=end;var+=inc)
#define ForDec(var,end,beg) for(int var=end;var>=beg;--var)
#define F(i,n) ForInc(i,0,n-1)
#define F1(i,n) ForInc(i,1,n)
#define ipArray(arr,size) ForInc(i,0,size-1) si(arr[i]);
#define ipllArray(arr,size) ForInc(i,0,size-1) sill(arr[i]);
#define ii pair<int,int>
#define mp make_pair
#define pb push_back
#define READ(f) freopen(f,"r",stdin);
#define WRITE(f) freopen(f,"w",stdout);
template<typename T> T gcd(T a, T b) { return (b == 0) ? abs(a) : gcd(b, a % b); }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> inline T mod(T a, T b) { return (a % b + b) % b; }
template<typename T> inline T sqr(T x) { return ((x) * (x)); }

const double EPS = 1e-9;
const double BIG = 1e19;
const int INF = INT_MAX;

typedef long long ll;

/* Main Code starts here :) */
int a,b,k;
int main(){
    READ("small.in");
    WRITE("small.out");
    int numcases;cin>>numcases;
    for(int case_id=1;case_id<=numcases;++case_id){
        cin>>a>>b>>k;
        int ans=0;
        F(i,a){
            F(j,b){
                if((i&j)<k)ans++;
            }
        }

        printf("Case #%d: ",case_id);
        printf("%d\n",ans);
    }
}
