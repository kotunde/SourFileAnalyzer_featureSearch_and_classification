#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <map>

#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#define debug
#define lp(i,n) for(int i=0;i<n;i++)
#define lpb(i,n) for(int i=1;i<=n;i++)
#define MA(a,b) ((a)>(b)?(a):(b))
#define MI(a,b) ((a)<(b)?(a):(b))
#define Read()    freopen("data.in", "r", stdin)
#define Write()   freopen("out.txt", "w", stdout);
#define PB push_back
#define FIR first
#define SEC second

#define _max 12
#define inf 0xfffffff
using namespace std;


vector <string> out;
int n,t;
long long int p,q;

long long int gcd(long long int x,long long int y){
    int i;
    while(y){ i=x%y; x=y; y =i; }
    return x;
}

void deal(){
  long long int tem = gcd(p,q);
  for(int i=2;i<=tem;i++){
    if(p%i==0&&q%i==0){
      p/=i; q/=i;
      i--;
    }
  }
}
char s[100];
void ch(){
  int x=0,m;
  while(s[x]!='/')x++;
  m=x;
  while(s[m])m++;
  
  p=0;q=0;
  long long int tt=1;
  for(int i=x-1;i>=0;i--){
      p+= tt*(s[i]-'0');
      tt*=10; 
  }tt=1;
  for(int i=m-1;i>x;i--){
      q+= tt*(s[i]-'0');
      tt*=10; 
  }   
}
int main(){

    
    Read();
    Write();
  cin>>t;
  lpb(kk,t){
    scanf("%s",s);
 
    ch();
    //cout<<p<<" "<<q<<endl;

    deal();
    
    
    long long int sum=0;
    long long int to=1;
    while(sum<=41){
      sum++; to = to*2;
      if(to==q)break;
    }
    if(sum<41){
       if( p*2>=q) printf("Case #%d: 1\n",kk,sum);
       else{
            sum=1;
            while(p*2<q){sum++;q/=2;}
       printf("Case #%d: %d\n",kk,sum);
       }
    }else
      printf("Case #%d: impossible\n",kk);
  }

    system("pause");
    return 0;
}





