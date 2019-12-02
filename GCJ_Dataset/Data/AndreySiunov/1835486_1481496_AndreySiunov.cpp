#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <list>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>
#include <list>
#include <set>
#include <stack>
#include <bitset>
#include <ctime>

#pragma comment(linker, "/STACK:256000000")

#define EPS 1e-7
#define PI 3.1415926535897932384626433832795

using namespace std;

int aabs(int a){
	if (a<0) return -a;
	return a;
}

int n;
int ana[300];
bool a[300][300];
string s;

int p[300], pi;
bool bb[300];

multiset <set <int> > cicles;
bool pp;

void next(int i){
	if (pp) return;
	if (pi>1 && p[pi-1]==p[0]){
		set <int> tmp;
		for (int j=1;j<pi;j++){
			tmp.insert(p[j]);
			a[p[j-1]][p[j]]=0;
		}
		cicles.insert(tmp);
		pp=true;
		return;
	}
	bb[i]=1;
	for (int j=0;j<300;j++){
		if (a[i][j]){
			if (j==p[0]){
				p[pi]=j;
				pi++;
				next(j);
			}
			else{
				if (!bb[j]){
					p[pi]=j;
					pi++;
					next(j);
					pi--;
				}
			}
		}
	}
}

void solve(){
	cin>>n>>s;
	n=s.size();
	memset(a,0,sizeof(a));
	for (int i=0;i<300;i++){
		ana[i]=i;
	}
	ana['o']='0';
	ana['i']='1';
	ana['e']='3';
	ana['a']='4';
	ana['s']='5';
	ana['t']='7';
	ana['b']='8';
	ana['g']='9';
	for (int i=1;i<n;i++){
		a[s[i-1]][s[i]]=1;
		a[ana[s[i-1]]][s[i]]=1;
		a[s[i-1]][ana[s[i]]]=1;
		a[ana[s[i-1]]][ana[s[i]]]=1;
	}
	for (int i=0;i<300;i++){
		while (true){
			p[0]=i;
			pi=1;
			memset(bb,0,sizeof(bb));
			pp=0;
			next(i);
			if (!pp){
				break;
			}
		}
	}
	int ans=0;
	memset(bb,0,sizeof(bb));
	for (int t=0;t<1300;t++){
		for (int i=0;i<300;i++){
			bool qq=0;
			for (int j=0;j<300;j++){
				if (a[j][i]){
					qq=1;
					break;
				}
			}
			if (!qq){
				for (int j=0;j<300;j++){
					if (a[i][j]){
						ans++;
						int q=i;
						bb[q]=1;
						while (true){
							bool fl=0;
							for (int k=0;k<300;k++){
								if (a[q][k]){
									ans++;
									a[q][k]=0;
									q=k;
									bb[k]=1;
									fl=1;
									break;
								}
							}
							if (!fl) break;
						}
					}
				}
			}
		}
	}
	while (!cicles.empty()){
		bool qq=0;
		for (multiset <set <int> >::iterator it1=cicles.begin();it1!=cicles.end();it1++){
			qq=0;
			for (set <int>::iterator it2=(*it1).begin();it2!=(*it1).end();it2++){
				if (bb[(*it2)]){
					ans+=(*it1).size();
					for (set <int>::iterator it2=(*it1).begin();it2!=(*it1).end();it2++){
						bb[(*it2)]=1;
					}
					cicles.erase(it1);
					qq=1;
					break;
				}
			}
			if (qq){
				break;
			}
		}
		if (!qq){
			multiset <set <int> >::iterator it1=cicles.begin();
			ans+=(*it1).size()+1;
			for (set <int>::iterator it2=(*it1).begin();it2!=(*it1).end();it2++){
				bb[(*it2)]=1;
			}
			cicles.erase(it1);
		}
	}
	cout<<ans;
	cout<<endl;
}

int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);

	// begin code
	//ios::sync_with_stdio(0);
	int t;
	cin>>t;
	for (int i=1;i<=t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	//end code

	return 0;
}
