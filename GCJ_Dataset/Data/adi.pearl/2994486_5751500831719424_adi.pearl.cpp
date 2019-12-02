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
#define ForInc(var,beg,end) for(int var=beg;var<=end;++var)
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
struct s{
    char ch;int cnt;
}x[1000+10],y[1000+10];
int main(){
    READ("small.in");
    WRITE("small.out");
    int numcases;cin>>numcases;
    string a,b;int n;
    for(int case_id=1;case_id<=numcases;++case_id){
        cin>>n;
        cin>>a>>b;
        int sx=0,sy=0;
        F(i,a.size()){
            int cnt=1;
            while(i<(a.size()-1) && a[i]==a[i+1]){i++;cnt++;}
            x[sx].ch=a[i];x[sx].cnt=cnt;sx++;
        }
        //F(i,sx)cout<<x[i].ch<<x[i].cnt;cout<<endl;
        F(i,b.size()){
            int cnt=1;
            while(i<(b.size()-1) && b[i]==b[i+1]){i++;cnt++;}
            y[sy].ch=b[i];y[sy].cnt=cnt;sy++;
        }
        //F(i,sy)cout<<y[i].ch<<y[i].cnt;cout<<endl;
        //db2(sx,sy);
        int ans=-1;
        if(sx==sy){
            ans=0;
            bool found=true;
            F(i,sx)
                if(x[i].ch==y[i].ch)ans+=abs(x[i].cnt-y[i].cnt);
                else {found=false;break;}
            if(found==false)ans=-1;
        }
        printf("Case #%d: ",case_id);
        if(ans==-1)printf("Fegla Won");
        else printf("%d",ans);
        printf("\n");
    }
}
