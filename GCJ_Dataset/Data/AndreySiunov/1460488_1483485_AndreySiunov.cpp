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

int gcd(int a, int b){
	while (a>0 && b>0){
		if (a>b){
			a%=b;
		}
		else{
			b%=a;
		}
	}
	return a+b;
}

void solve(){
	string s;
	getline(cin,s);
	string s1="qzejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
	string s2="zqour language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
	for (int i=0;i<s.length();i++){
		for (int j=0;j<s1.length();j++){
			if (s[i]==s1[j]){
				cout<<s2[j];
				break;
			}
		}
	}
	cout<<endl;
}

int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);

	//begin code
	//ios::sync_with_stdio(0);
	int t;
	cin>>t;
	string s;
	getline(cin,s);
	for (int ct=1;ct<=t;ct++){
		cout<<"Case #"<<ct<<": ";
		solve();
	}
	//end code

	return 0;
}