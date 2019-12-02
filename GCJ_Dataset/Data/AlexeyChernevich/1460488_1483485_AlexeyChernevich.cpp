#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;
map < char , char> mp;
string s = "yhesocvxduiglbkrztnwjpfmaq";
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	string tslate;
	getline(cin,tslate);
	for (int test = 0 ; test < n; test++)
	{
		getline(cin,tslate);
		cout << "Case #" << test + 1 <<": ";
		for (int i = 0 ; i < tslate.length(); i++)
		if (tslate[i] == ' ')
			cout << ' ';
		else
			cout << s[tslate[i] - 'a'];
		cout << '\n';
	}

	return 0;
}