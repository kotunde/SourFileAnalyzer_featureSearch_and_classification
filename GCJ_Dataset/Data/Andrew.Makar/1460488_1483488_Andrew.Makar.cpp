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


struct Input{
	int a,b;
	Input(int x,int y):a(x),b(y){}
	Input():a(),b(){}

	void read(){
		cin>>a>>b;
	}
};

set<pair<int,int> >s;


void solve(const Input& input){
	int a=input.a;
	int b=input.b;
	s.clear();

	int A=a;
	int cnt=0;
	int pp=1;
	while(A){
		cnt++;
		A/=10;
		pp*=10;
	}
	pp/=10;


	for (int i=a; i<=b; i++){

		A=i;

		for (int j=1; j<cnt; j++){
			int x=A%10;
			A/=10;
			A+=pp*x;
			
			if (A>=a && A<=b && i<A) s.insert(MP(min(A,i),max(i,A)));
		}

	}

	cout<<s.size()<<endl;
}



int main(){
	

	

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int tt;
	cin>>tt;
	
	for (int t=1; t<=tt; t++){
		
		Input* input=new Input();
		input->read();

		cout<<"Case #"<<t<<": ";

		solve(*input);


	}
	
	


}