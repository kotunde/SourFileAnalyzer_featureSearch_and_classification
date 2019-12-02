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
#define ii pair<int,int>
#define mp make_pair
#define pb push_back
#define R(f) freopen(f,"r",stdin);
#define W(f) freopen(f,"w",stdout);
template<typename T> T gcd(T a, T b) { return (b == 0) ? abs(a) : gcd(b, a % b); }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> inline T sqr(T x) { return ((x) * (x)); }
const double EPS = 1e-9;
const double BIG = 1e19;
const int INF = INT_MAX;
typedef long long ll;

/* Main Code starts here :) */
int n;string s[100+10];
const int mod=1000000007;
int arr[]={0,1,2,3,4,5,6,7,8,9},v[11];
bool valid(string s){
    bool ret=1;int sz=s.size();
    int i=0;vector<bool> a(26,false);
    while(i<sz){
        while(i<sz-1 && s[i]==s[i+1])i++;
        if(a[ s[i]-'a' ]==1){ret=0;break;}
        a[ s[i]-'a' ]=1;
        i++;
    }
    return ret;
}
int main(){
    R("small.in");W("small.out");
    int numcases;cin>>numcases;
    for(int case_id=1;case_id<=numcases;++case_id){
        cin>>n;F(i,n)cin>>s[i];
        F(i,n)v[i]=arr[i];
        int ans=0;
        do{
            string r="";F(i,n)r+=s[ v[i] ];
            if(valid(r))ans=(ans+1)%mod;
        }while(next_permutation(v,v+n));

        printf("Case #%d: ",case_id);
        printf("%d\n",ans);
    }
}
