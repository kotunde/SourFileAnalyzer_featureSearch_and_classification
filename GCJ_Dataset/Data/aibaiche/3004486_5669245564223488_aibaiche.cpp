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
#define Write()   freopen("out1.txt", "w", stdout);
#define PB push_back
#define FIR first
#define SEC second

#define _max 12
#define inf 0xfffffff
#define mod 1000000007
using namespace std;


vector <string> out;
int ss[110][2];
int n,t;
long long int p,q;
int inside[30],couS[30],couE[30],same[30];
string s;

int main(){

    
    Read();
    Write();
  scanf("%d",&t);
  lpb(kk,t){
    cin>>n;
    memset(inside,0,sizeof(inside));
    memset(couS,0,sizeof(couS));
    memset(couE,0,sizeof(couE));
    memset(same,0,sizeof(same));
    bool fl=true;
   char temC;
    lp(i,n){
      cin>>s;
      char x=s[0];
      int change=0;
      int temS = s[0]-'a';
      int temE = s[s.length()-1]-'a';
      
     // cout<<temS<<" "<<temE<<endl;
      couS[ temS ]++;
      //ss[i][1] = s[s.length()-1]-'a';

      if(temS == temE ){ couS[temS ]--; same[temS]++;}
      else couE[ temE ]++;

      if(couS[temS]>1 || couE[temE]>1) fl=false;
      bool fff=false;
      if(s[0]==s[s.length()-1])fff=true;
      for(int j=0;j<s.length();j++){
        if(fff && s[j]!=s[0]){ fl=false;break;}
        if(inside[s[j]-'a']==1&&s[j]!=temC){ //cout<<s<<endl;cout<<s[j]<<endl;cout<<j<<endl;
        
         fl=false;break;}
        
        if(s[j]!=s[0]&&s[j]!=s[s.length()-1] )
            //if(inside[s[j]-'a']==1)
               //{fl=false;break;}
            //else 
            inside[s[j]-'a']=1;
        temC=s[j];
        }
        
    }// end lp n
    //if(!fl)cout<<"$"<<endl;
    //for(int i=0;i<26;i++){cout<<same[i]<<" ";}

    int start=0,end=0,singles=0;
    int ssum = n;
    for(int i=0;i<26;i++){
        if(couS[i]>1 ||  couE[i]>1){
           fl=false;break;
        }
        //if(couS[i]==0&&couE[i]==1) end++;
        //if(couS[i]==1&&couE[i]==0) start++;
        
        if(couS[i]==1&&couE[i]==1){ ssum--; }
    }
    //if(!(start==1&&end==1)) fl=false;
//if(!fl)cout<<"$"<<endl;
    if(!fl){
      printf("Case #%d: 0\n",kk);
    }else{
      long long int sum=1;
      long long int count=0;
      //cout<<ssum<<endl;
      for(int i=0;i<26;i++){
        if(same[i]>0){
          if(couS[i]==0&&couE[i]==0)
          count++;
          for(int kkk=1;kkk<=same[i];kkk++) sum = (sum*kkk)%mod;
          
          ssum=ssum - same[i]+1;
          
          if(couS[i]==1||couE[i]==1) ssum--;
        }
        
      }
      //for(int kkk=1;kkk<=count;kkk++) sum = (sum*kkk)%mod;
      //if(count>0) sum = (sum*2)%mod;
      
      for(int kkk=1;kkk<=ssum;kkk++) sum = (sum*kkk)%mod;
      printf("Case #%d: ",kk);
      cout<<sum<<endl;

    }
    
}
    //system("pause");
    return 0;
}





