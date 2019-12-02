#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

#define MP make_pair
#define PB push_back

int T;
int n[100],a[100][100],h[100][100];
vector<vector<int> > ans;

inline int getrand(int mo){
	int k=((rand()&65535)<<15)+(rand()&65535);
	return k%mo;
}

inline int getid(int z,int i){
	int res=i+1;
	for (int j=i+2;j<n[z];j++){
		if ((res-i)*(long long)(h[z][j]-h[z][i])>(j-i)*(long long)(h[z][res]-h[z][i])) res=j;
	}
	return res;
}

inline bool check(int i){
	for (int z=0;z<n[i];z++) h[i][z]=getrand(100000);
	for (int z=0;z<n[i]-1;z++) if (getid(i,z)!=a[i][z]) return false;
	vector<int> q;
	q.clear();
	for (int z=0;z<n[i];z++) q.PB(h[i][z]);
	ans[i]=q;
	return true;
}

void makeans(int i){
	check(i);
}

int main(){
	scanf("%d",&T);
	ans=vector<vector<int> >(T,vector<int>(0));
	for (int z=0;z<T;z++){
		scanf("%d",&n[z]);
		for (int i=0;i<n[z]-1;i++) scanf("%d",&a[z][i]),a[z][i]--;
	}
	int now=0;
	for (;clock()/(double)CLOCKS_PER_SEC<200;now=(now+1)%T){
		if (ans[now].size()) continue;
		makeans(now);
	}
	for (int i=0;i<T;i++){
		printf("Case #%d:",i+1);
		if (ans[i].size()==0) puts(" Impossible");
		else {for (int z=0;z<ans[i].size();z++) printf(" %d",ans[i][z]);puts("");}
	}
    return 0;
}

