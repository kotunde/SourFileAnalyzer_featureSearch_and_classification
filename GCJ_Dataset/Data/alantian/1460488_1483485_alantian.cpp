#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

char tr[128];

int main(){
	for( int i = 0; i < 128; i++ )
		tr[i] = i;
	tr['y'] = 'a';
	tr['n'] = 'b';
	tr['f'] = 'c';
	tr['i'] = 'd';
	tr['c'] = 'e';
	tr['w'] = 'f';
	tr['l'] = 'g';
	tr['b'] = 'h';
	tr['k'] = 'i';
	tr['u'] = 'j';
	tr['o'] = 'k';
	tr['m'] = 'l';
	tr['x'] = 'm';
	tr['s'] = 'n';
	tr['e'] = 'o';
	tr['v'] = 'p';
	tr['z'] = 'q';
	tr['p'] = 'r';
	tr['d'] = 's';
	tr['r'] = 't';
	tr['j'] = 'u';
	tr['g'] = 'v';
	tr['t'] = 'w';
	tr['h'] = 'x';
	tr['a'] = 'y';
	tr['q'] = 'z';
	string s;
	getline(cin,s);
	stringstream ss(s);
	int n;
	ss>>n;
	for( int i = 0; i < n; i++ ){
		getline(cin,s);
		cout << "Case #" << (i+1)<<": ";
		for( int j = 0 ; j < (int)s.length(); j++ )
			cout<<tr[s[j]];
		cout<<endl;
	}
	return 0; }
