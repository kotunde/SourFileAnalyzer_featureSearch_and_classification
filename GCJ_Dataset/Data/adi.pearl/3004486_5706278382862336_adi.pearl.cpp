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
//others
#define F(i,n) for(int i=0;i <= n-1;++i)
#define F1(i,n) for(int i=1;i <= n;++i)
#define ipArray(arr,size) F(i,size) si(arr[i]);
#define ii pair<ll,ll>
#define mp make_pair
#define pb push_back
#define R(f) freopen(f,"r",stdin);
#define W(f) freopen(f,"w",stdout);
template<typename T> T gcd(T a, T b) { return (b == 0) ? abs(a) : gcd(b, a % b); }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> inline T mod(T a, T b) { return (a % b + b) % b; }
template<typename T> inline T sqr(T x) { return ((x) * (x)); }
const double EPS = 1e-9;
const double BIG = 1e19;
const int INF = INT_MAX;
typedef long long ll;

/* Main Code starts here :) */
#define f first
#define s second
ii minimise(ii x){
    //dbm2("in:",x.f,x.s);
    ll p=x.f,q=x.s,g;
    while((g=gcd(p,q))!=1LL){
        p/=g;q/=g;
    }
    return mp(p,q);
}
ll p,q;
inline void getpq(string s){
    p=0,q=0;
    int i=0,sz=s.size();while(s[i]!='/'){p=(p*10)+(s[i]-'0');i++;}
    i++;while(i<sz){q=(q*10)+(s[i]-'0');i++;}
}
int main(){
    R("small.in");W("small.out");
    int numcases;cin>>numcases;
    string s;
    for(int case_id=1;case_id<=numcases;++case_id){
        cin>>s;getpq(s);
        //dbm("done");
        ii no=minimise(mp(p,q));
        //dbm("done2");
        p=no.f;q=no.s;
        printf("Case #%d: ",case_id);
        //db2(p,q);
        if(p>q || ceil(log2(q)) != log2(q))printf("impossible");
        else{
            int ans=1;
            while(p < (q/2LL)){ans++;q/=2LL;}
            printf("%d",ans);
        }
        printf("\n");
    }
}
