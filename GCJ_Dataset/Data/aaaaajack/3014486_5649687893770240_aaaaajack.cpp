#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<set>
using namespace std;
int cnt[200];
string s[10];
set<string> trie[10];
void bf(int now,int n,int m){
	bool in[20][20]={0};
	int i,j;
	string temp;
	if(now==m){
		int ans=0;
		for(i=0;i<n;i++){
			if(trie[i].empty()) return;
		}
		for(i=0;i<n;i++){
			ans+=trie[i].size();
		}
		cnt[ans]++;
		return;
	}
	for(i=0;i<n;i++){
		for(j=1;j<=s[now].size();j++){
			temp=s[now].substr(0,j);
			if(trie[i].count(temp)){
				in[i][j]=true;
			}
			else trie[i].insert(temp);
		}
		bf(now+1,n,m);
		for(j=1;j<=s[now].size();j++){
			temp=s[now].substr(0,j);
			if(!in[i][j]) trie[i].erase(temp);
		}
	}
}
int main(){
	int t,c,n,m,i;
	scanf("%d",&t);
	for(c=1;c<=t;c++){
		scanf("%d%d",&m,&n);
		memset(cnt,0,sizeof(cnt));
		for(i=0;i<m;i++) cin>>s[i];
		bf(0,n,m);
		i=199;
		while(!cnt[i]) i--;
		printf("Case #%d: %d %d\n",c,i+n,cnt[i]);
	}
	return 0;
}