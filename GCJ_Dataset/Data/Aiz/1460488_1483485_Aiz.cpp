#include <iostream>
#include <string>

using namespace std;

char z[256] = {0};

void init()
{
	z['a'] = 'y';
	z['b'] = 'h';
	z['c'] = 'e';
	z['d'] = 's';
	z['e'] = 'o';
	z['f'] = 'c';
	z['g'] = 'v';
	z['h'] = 'x';
	z['i'] = 'd';
	z['j'] = 'u';
	z['k'] = 'i';
	z['l'] = 'g';
	z['m'] = 'l';
	z['n'] = 'b';
	z['o'] = 'k';
	z['p'] = 'r';
	z['q'] = 'z';
	z['r'] = 't';
	z['s'] = 'n';
	z['t'] = 'w';
	z['u'] = 'j';
	z['v'] = 'p';
	z['w'] = 'f';
	z['x'] = 'm';
	z['y'] = 'a';
	z['z'] = 'q';
}

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  init();
  int T;
  cin >> T;
  cin.ignore(101,'\n');
  for (int t = 1; t <= T; t++)
  {
    cout << "Case #" << t << ": ";
		string s;
		getline(cin, s);
		for (int i = 0; i < s.length(); i++)
			if (z[s[i]])
				s[i] = z[s[i]];
		cout << s;
    cout << endl;
  }
  return 0;
}