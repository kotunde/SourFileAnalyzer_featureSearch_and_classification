#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#include <stdlib.h>
#include <sstream>
#include <ctime>
#include <fstream>
using namespace std;
 
using namespace std;
 
#define INF 1000000000
#define PI acos(-1.0)
#define MP make_pair
double EPS=1e-7;
#define MOD 1000000007 

char c[26];
bool b[26];

char a[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int tt;
	cin>>tt;
	string _47747447;
	getline(cin,_47747447);
	for (int t=1; t<=tt; t++){
		string s;
		getline(cin,s);
		cout<<"Case #"<<t<<": ";
		for (int i=0; i<s.length(); i++){
			if (s[i]==' ') continue;
			s[i]=a[s[i]-'a'];
		}
		cout<<s<<endl;
	}
	
	/*string s1,s2;
	while(1){
		if (!getline(cin,s1)) break;
		getline(cin,s2);
		for (int i=0; i<s1.length(); i++){
			if (s1[i]==' ') continue;
			c[s1[i]-'a']=s2[i];
			b[s2[i]-'a']=1;
		}
	}

	int x;
	for (int i=0; i<26; i++){
		if (!b[i]) x=i+'a';
	}

	for (int i=0; i<26; i++){
		if (c[i]==0) c[i]='q';
		cout<<"'"<<c[i]<<"',";
	}
	*/


}