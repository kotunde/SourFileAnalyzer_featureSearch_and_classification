#include <iostream>
using namespace std;

int decode[300];
string encoded[3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","de kr kd eoya kw aej tysr re ujdr lkgc jvzq"};
string decoded[3] = {"our language is impossible to understand","there are twenty six factorial possibilities","so it is okay if you want to just give upqz"};
string s;
int i, j;

int main ()
{
	for ( i = 0; i < 3; i++ )
	{
		for ( j = 0; j < (encoded[i]).size(); j++ )
		{
			decode[encoded[i][j]] = decoded[i][j];
		}
	}
	
	int T;
	cin >> T;
	getline(cin,s);
	
	for ( i = 1; i <= T; i++ )
	{
		getline(cin,s);
		for ( j = 0; j < s.size(); j++ ) if ( s[j] <= 'z' && s[j] >= 'a' ) s[j] = decode[s[j]];
		cout << "Case #" << i << ": ";
		cout << s << endl;
	}
}